#include "handler.h"
#include "horse.h"
#include "plane.h"
#include <QJsonDocument>
#include <QJsonArray>

QJsonObject jackal::Handler::get_current_game_state(Game& game) {
    QJsonObject qObj;

    qObj["game"] = "Jackal";
    qObj["response_type"] = "game_state";
    qObj["current_player"] = game.m_current_player;

    QJsonArray players_data;
    int player_id = 0;
    for (const auto& player : game.m_players) {
        QJsonObject data;

        data["player_id"] = player_id++;
        data["total_coins"] = player->get_coins_earned();

        auto pirates = player->get_all_pirates();
        QJsonArray pirates_data;
        int pirate_id = 0;

        for (const auto& pirate : pirates) {
            QJsonObject p_data;
            Coords pirate_coords = pirate->get_coords();

            p_data["pirate_id"] = pirate_id++;
            p_data["coord_x"] = pirate_coords.x;
            p_data["coord_y"] = pirate_coords.y;
            p_data["coins_amount"] = pirate->get_coins_amount();
            p_data["is_dead"] = (pirate->get_status() == status::DEAD);

            pirates_data.append(p_data);
        }
        Coords ship_coords = player->get_ship_coords();

        data["pirates"] = pirates_data;
        data["ship_coord_x"] = ship_coords.x;
        data["ship_coord_y"] = ship_coords.y;

        players_data.append(data);
    }
    qObj["players_data"] = players_data;

    QJsonArray field_data;
    const Field& game_field = game.get_field();
    for (int i = 0; i <= COORD_UPPER_BOUND; i++) {
        for (int j = 0; j<= COORD_UPPER_BOUND; j++) {
            QJsonObject data;
            Event& event = game_field.get_element(j, i);

            data["coord_x"] = j;
            data["coord_y"] = i;
            data["is_open"] = event.opened_status();
            data["coins"] = event.get_coins_amount();
            data["filename"] = QString::fromStdString(event.get_filename());

            field_data.append(data);
        }
    }

    qObj["field_data"] = field_data;
    return qObj;
}

QJsonObject jackal::Handler::get_possible_moves(Game& game, int pirate_id, eventType type, Coords coords) {
    QJsonObject qObj;

    qObj["game"] = "Jackal";
    qObj["response_type"] = "possible_moves";

    auto pirate_to_go = game.m_players[game.m_current_player]->get_pirate(pirate_id);
    Coords cur_coords = pirate_to_go->get_coords();

    QJsonArray coords_to_go;

    for (int i = 0; i <= COORD_UPPER_BOUND; i++) {
        for (int j = 0; j <= COORD_UPPER_BOUND; j++) {
            QJsonObject data;
            if ( (type == eventType::SIMPLE && !game.check_move_correctness(pirate_to_go, {j, i}) ) ||
                 (type == eventType::HORSE && !Horse::check_move_correctness(cur_coords, Coords{j, i})) ||
                 (type == eventType::PLANE && !Plane::check_move_correctness(Coords{j, i}) )) {
                continue;
            }
            data["coord_x"] = j;
            data["coord_y"] = i;
            coords_to_go.append(data);
        }
    }

    qObj["coords_to_go"] = coords_to_go;
    return qObj;
}

QJsonObject jackal::Handler::get_error_json(const std::string &error) {
    QJsonObject qObj;

    qObj["game"] = "Jackal";
    qObj["response_type"] = "requests_error";
    qObj["error"] = QString::fromStdString(error);
    return qObj;
}
