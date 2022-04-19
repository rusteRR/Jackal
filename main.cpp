/*
 * This file is temporary until the GUI will not be implemented.
 */


#include "game.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::pair<std::string, std::vector<int>> parse_input(const std::string& input) {
    std::string command;
    std::stringstream ss(input);
    ss >> command;
    std::vector<int> tokens;
    std::string current_token;
    while (ss >> current_token) {
        tokens.push_back(std::stoi(current_token));
    }
    return {command, tokens};
}

int main() {
    // TODO : only one game type is supported with 4 players
    jackal::Game current_game(jackal::game_type::DEFAULT);
    // A temporary version of the player's interaction with game
    //                Pirate coords            new coords
    // Input format : col_coord row_coord      col_coord row_coord
    std::string command;
    while (std::getline(std::cin, command)) {
        auto tokens = parse_input(command);
        current_game.process_move(tokens.first, tokens.second[0], tokens.second[1], tokens.second[2], tokens.second[3]);
    }
}