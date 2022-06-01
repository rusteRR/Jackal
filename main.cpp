/*
 * This file is temporary until the GUI will not be implemented.
 */


#include "game.h"
#include "handler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QJsonDocument>
#include <vector>
#include <QJsonArray>

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
    QJsonObject result;
    while (std::getline(std::cin, command)) {
        auto tokens = parse_input(command);
        QJsonObject a = jackal::Handler::get_possible_moves(current_game, 0);
        std::cout << QJsonDocument(a).toJson(QJsonDocument::Compact).toStdString() << std::endl;
        if (tokens.second.size() == 1) {
            result = current_game.process_move(tokens.first, tokens.second[0]);
        }
        else if (tokens.first == "ship_move"){
            result = current_game.process_move(tokens.first, -1, tokens.second[0], tokens.second[1]);
        }
        else {
            result = current_game.process_move(tokens.first, tokens.second[0], tokens.second[1], tokens.second[2]);
        }
        std::cout << QJsonDocument(result).toJson(QJsonDocument::Compact).toStdString() << std::endl;
    }
}