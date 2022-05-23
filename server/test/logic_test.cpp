#include "game.h"
#include "handler.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <set>

using namespace jackal;

namespace {
    constexpr int FIELD_SZ = 13;

    const std::vector<std::pair<int, int>> coords = {
            {FIELD_SZ / 2, 0},
            {FIELD_SZ - 1, FIELD_SZ / 2},
            {FIELD_SZ / 2, FIELD_SZ - 1},
            {0, FIELD_SZ / 2}
    };

    void CHECK(bool res, int& exit_code) {
        if (!res) {
            exit_code = 1;
        }
    }
}

int COORD_TEST() {
    std::cout << "Coord test" << std::endl;
    int exit_code = 0;
    Game cur_game(game_type::DEFAULT);
    QJsonObject result = Handler::get_current_game_state(cur_game);
    QJsonArray players_data = result["players_data"].toArray();
    for (int i = 0; i < 4; i++) {
        QJsonArray first_pirates = players_data[i].toObject()["pirates"].toArray();
        // std::cout << QJsonDocument(players_data[i].toObject()).toJson(QJsonDocument::Compact).toStdString() << std::endl;
        CHECK(first_pirates[0].toObject()["coord_x"] == coords[i].first, exit_code);
        CHECK(first_pirates[1].toObject()["coord_x"] == coords[i].first, exit_code);
        CHECK(first_pirates[2].toObject()["coord_x"] == coords[i].first, exit_code);
        CHECK(first_pirates[0].toObject()["coord_y"] == coords[i].second, exit_code);
        CHECK(first_pirates[1].toObject()["coord_y"] == coords[i].second, exit_code);
        CHECK(first_pirates[2].toObject()["coord_y"] == coords[i].second, exit_code);
    }
    if (exit_code == 1) {
        std::cerr << "FAIL" << std::endl;
    }
    else {
        std::cout << "PASS" << std::endl;
    }
    return exit_code;
}

int OPEN_CELLS_TEST() {
    std::cout << "Open cells test" << std::endl;
    Game cur_game(game_type::DEFAULT);
    QJsonObject result = cur_game.process_move("pirate_move", 0, 6, 1);
    QJsonArray field_data = result["field_data"].toArray();
    int exit_code = 0;
    CHECK(field_data[FIELD_SZ + 6].toObject()["is_open"].toBool(), exit_code);
    if (exit_code == 1) {
        std::cerr << "FAIL" << std::endl;
    }
    else {
        std::cout << "PASS" << std::endl;
    }
    return exit_code;
}

int POINTERS_TEST() {
    std::cout << "Pointers test" << std::endl;
    int exit_code = 0;
    Game cur_game(game_type::DEFAULT);
    auto all_pirates = cur_game.get_pirates();
    std::set<Pirate*> pointers;
    for (const auto& elem : all_pirates) {
        pointers.insert(elem.get());
    }
    CHECK(pointers.size() == 9, exit_code);
    if (exit_code == 1) {
        std::cerr << "FAIL" << std::endl;
    }
    else {
        std::cout << "PASS" << std::endl;
    }
    return exit_code;
}

int main() {
    int exit_code = 0;
    exit_code = std::max(COORD_TEST(), exit_code);
    exit_code = std::max(OPEN_CELLS_TEST(), exit_code);
    exit_code = std::max(POINTERS_TEST(), exit_code);
    if (exit_code == 0) {
        std::cout << "ALL PASS" << std::endl;
    }
    else {
        std::cerr << "SOME FAIL" << std::endl;
    }
}