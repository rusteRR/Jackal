/*
 * This file is temporary until the GUI will not be implemented.
 */


#include "game.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> parse_input(const std::string& input) {
    std::stringstream ss(input);
    std::vector<int> tokens;
    std::string current_token;
    while (ss >> current_token) {
        tokens.push_back(std::stoi(current_token));
    }
    return tokens;
}

int main() {
    // TODO : only one game type is supported with 4 players
    jackal::Game current_game(jackal::game_type::DEFAULT);
    // A temporary version of the player's interaction with game
    //                Pirate coords            new coords
    // Input format : col_coord row_coord      col_coord row_coord
    std::string command;
    while (std::getline(std::cin, command)) {
        std::vector<int> tokens = parse_input(command);
        current_game.process_move(tokens[0], tokens[1], tokens[2], tokens[3]);
    }
}