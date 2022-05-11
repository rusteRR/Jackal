#include "game.h"
#include "handler.h"
#include <algorithm>
#include <QJsonObject>
#include <iostream>


QJsonObject jackal::Game::process_move(const std::string& request_type, int pirate_id, int col_to, int row_to) {
    Coords new_coords = {col_to, row_to};

    if (request_type == "take_coin") {
        bool step_result = take_coin(pirate_id);
        if (!step_result) {
            return Handler::get_error_json(request_type);
        }
    }

    else if (request_type == "ship_move") {
        bool step_result = m_players[m_current_player].move_ship(new_coords);
        if (step_result) {
            change_turn();
        }
    }

    else if (request_type == "pirate_move") {
        std::shared_ptr<Pirate> pirate_to_go = m_players[m_current_player].get_pirate(pirate_id);

        if (!check_move_correctness(pirate_to_go, new_coords) || !pirate_to_go) {
            return Handler::get_error_json(request_type);
        }
        Event &current_event = m_field.get_element(col_to, row_to);

        if (pirate_to_go->get_status() == status::PROTECTED ||
                pirate_to_go->get_status() == status::JUNGLE) {
            pirate_to_go->set_status(status::ALIVE);
        }
        Coords coords = pirate_to_go->get_coords();
        pirate_to_go->move(new_coords);
        pirate_to_go->set_last_move(eventType::SIMPLE, coords);
        pirate_to_go->attack_pirate(*this);
        auto n = current_event.get_filename();
        EventType event_type = current_event.invoke(*pirate_to_go);
        while (event_type != EventType::SIMPLE) {
            coords = pirate_to_go->get_coords();
            Event& new_event = m_field.get_element(coords.x, coords.y);
            event_type = new_event.invoke(*pirate_to_go);
            pirate_to_go->attack_pirate(*this);
        }
        drop_coin(pirate_id);
        change_turn();
        Coords coords_to_go = pirate_to_go->get_coords();
    }

    else {
        return Handler::get_error_json("incorrect_command");
    }

    return Handler::get_current_game_state(*this);
}

bool jackal::Game::check_move_correctness(const std::shared_ptr<Pirate>& pirate_to_go, Coords new_coords) {
    auto coords = pirate_to_go->get_coords();
    Event &current_event = m_field.get_element(new_coords.x, new_coords.y);
    auto cur_status = pirate_to_go->get_status();
    if (cur_status == status::DEAD || cur_status == status::STUCK) {
        return false;
    }
    if (cur_status == status::CARRYING_COIN && !current_event.opened_status()) {
        return false;
    }
    if (cur_status == status::CARRYING_COIN && !current_event.is_available_with_coin()) {
        return false;
    }
    if (abs(coords.x - new_coords.x) > 1 || abs(coords.y - new_coords.y) > 1) {
        return false;
    }
    if (cur_status != status::DROWN && Game::check_is_water_cell(new_coords)) {
        return false;
    }
    if (cur_status == status::DROWN && !Game::check_is_water_cell(new_coords)) {
        return false;
    }
    if (cur_status == status::CARRYING_COIN && check_if_pirates_on_cell(coords)) {
        return false;
    }
    return true;
}

jackal::Game::Game(game_type type) : m_current_player(0), m_game_type(type), coins_remaining(37) {
    m_field.generate_field(m_settings);

    m_players.emplace_back(total_pirates, m_total_cols / 2, 0);
    m_players.emplace_back(total_pirates, m_total_cols - 1, m_total_rows / 2);
    m_players.emplace_back(total_pirates, m_total_cols / 2, m_total_rows - 1);
    m_players.emplace_back(total_pirates, 0, m_total_rows / 2);
}

void jackal::Game::change_turn() noexcept {
    m_current_player = (m_current_player + 1) % 4;
}

std::vector<std::shared_ptr<jackal::Pirate>> jackal::Game::get_pirates() const {
    std::vector<std::shared_ptr<Pirate>> result;
    for (int i = 0; i < 4; i++) {
        if (i == m_current_player) {
            continue;
        }
        auto cur_pirate = m_players[i].get_all_pirates();
        result.insert(result.end(), cur_pirate.begin(), cur_pirate.end());
    }
    return result;
}

bool jackal::Game::take_coin(int pirate_id) {
    auto pirate_to_go = m_players[m_current_player].get_pirate(pirate_id);
    Coords coords = pirate_to_go->get_coords();
    Event &current_event = m_field.get_element(coords.x, coords.y);
    if (pirate_to_go) {
        bool result = current_event.take_coin(*pirate_to_go);
        if (result) {
            return true;
        }
    }
    return false;
}

const jackal::Field &jackal::Game::get_field() const {
    return m_field;
}

bool jackal::Game::check_win() const {
    int coins_in_game = coins_remaining;
    auto all_pirates = get_pirates();
    for (const auto& pirate : all_pirates) {
        coins_in_game += pirate->get_coins_amount();
    }

    // REM: std::pair<X, Y>, X - coins earned, Y - player id.
    std::vector<std::pair<int, int>> coins_earned(m_players.size());

    for (int i = 0; i < m_players.size(); i++) {
        coins_earned[i] = {m_players[i].get_coins_earned(), i};
    }
    std::sort(coins_earned.rbegin(), coins_earned.rend());
    if (coins_earned[0].first > coins_earned[1].first + coins_in_game) {
        std::cout << "Player " + std::to_string(coins_earned[0].second) + " is winner!" << std::endl;
        return true;
    }
    return false;
}

void jackal::Game::drop_coin(int pirate_id) {
    auto pirate_to_go = m_players[m_current_player].get_pirate(pirate_id);
    Coords coords = pirate_to_go->get_coords();
    Event &current_event = m_field.get_element(coords.x, coords.y);
    if (pirate_to_go->get_status() == status::CARRYING_COIN) {
        int dropped_coins = pirate_to_go->drop_coin();
        coins_remaining += dropped_coins;
        current_event.increase_coins(dropped_coins);
    }
}

bool jackal::Game::check_is_water_cell(const jackal::Coords coords) {
    return (coords.x == COORD_LOWER_BOUND || coords.x == COORD_UPPER_BOUND ||
            coords.y == COORD_LOWER_BOUND || coords.y == COORD_UPPER_BOUND);
}

bool jackal::Game::check_if_pirates_on_cell(const jackal::Coords coords) {
    for (int i = 0; i < m_players.size(); i++) {
        if (i == m_current_player) continue;
        auto pirates = m_players[i].get_all_pirates();
        for (const auto& pirate : pirates) {
            if (pirate->get_coords() == coords) {
                return true;
            }
        }
    }
    return false;
}
