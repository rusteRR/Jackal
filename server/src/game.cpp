#include "game.h"
#include <algorithm>
#include <iostream>


void jackal::Game::process_move(const std::string& request_type, int pirate_id, int col_to, int row_to) {
    Coords new_coords = {col_to, row_to};

    if (request_type == "take_coin") {
        take_coin(pirate_id);
    }

    else if (request_type == "drop_coin") {
        drop_coin(pirate_id);
    }

    else if (request_type == "ship_move") {
        m_players[m_current_player].move_ship(new_coords);
        change_turn();
    }

    else if (request_type == "move") {
        std::shared_ptr<Pirate> pirate_to_go = m_players[m_current_player].get_pirate(pirate_id);

        if (!check_move_correctness(pirate_to_go, new_coords)) {
            std::cout << "Incorrect pirate move with id: " + std::to_string(pirate_id) << std::endl;
            return;
        }
        Event &current_event = m_field.get_element(col_to, row_to);

        // TODO : need to change pirate's status after leaving fortress. Is not implemented now.
        if (pirate_to_go) {
            Coords coords = pirate_to_go->get_coords();
            pirate_to_go->move(new_coords);
            pirate_to_go->set_last_move(eventType::SIMPLE, coords);
            pirate_to_go->attack_pirate(*this);
            auto n = current_event.get_filename();
            EventType event_type = current_event.invoke(*pirate_to_go);
            while (event_type != EventType::SIMPLE) {
                coords = pirate_to_go->get_coords();
                Event& new_type = m_field.get_element(coords.x, coords.y);
                pirate_to_go->attack_pirate(*this);
                event_type = new_type.invoke(*pirate_to_go);
            }
            change_turn();
        }
        else {
            std::cout << "Incorrect move!" << std::endl;
        }
    }
    else {
        std::cout << "Incorrect command" << std::endl;
    }


}

bool jackal::Game::check_move_correctness(const std::shared_ptr<Pirate>& pirate_to_go, Coords new_coords) {
    // TODO : can't go to not opened cells

    auto coords = pirate_to_go->get_coords();
    Event &current_event = m_field.get_element(new_coords.x, new_coords.y);
    if (pirate_to_go->get_status() == status::CARRYING_COIN && !current_event.opened_status()) {
        return false;
    }
    if (pirate_to_go->get_status() == status::CARRYING_COIN && !current_event.is_available_with_coin()) {
        return false;
    }
    if (abs(coords.x - new_coords.x) > 1 || abs(coords.y - new_coords.y) > 1) {
        return false;
    }
    if (pirate_to_go->get_status() == status::DROWN) {
        // TODO : need to check that we don't leave water
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
        std::vector<std::shared_ptr<Pirate>> cur_pirate = m_players[i].get_all_pirates();
        result.insert(result.end(), cur_pirate.begin(), cur_pirate.end());
    }
    return result;
}

void jackal::Game::take_coin(int pirate_id) {
    auto pirate_to_go = m_players[m_current_player].get_pirate(pirate_id);
    Coords coords = pirate_to_go->get_coords();
    Event &current_event = m_field.get_element(coords.x, coords.y);
    if (pirate_to_go) {
        std::string result = current_event.take_coin(*pirate_to_go);
    }
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
    else {
        std::cout << "This pirate doesn't have a coin!" << std::endl;
    }
}
