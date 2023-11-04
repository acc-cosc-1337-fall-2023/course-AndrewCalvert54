#include "tic_tac_toe_manager.h"
#include <iostream>

TicTacToeManager::TicTacToeManager() {
    // Constructor code here
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe> game) {
    games.push_back(std::move(game)); // Use std::move to transfer ownership
    update_winner_count(games.back()->get_winner());
}

int TicTacToeManager::get_x_wins() const {
    return x_win;
}

int TicTacToeManager::get_o_wins() const {
    return o_win;
}

int TicTacToeManager::get_ties() const {
    return ties;
}

void TicTacToeManager::update_winner_count(char winner) {
    if (winner == 'X') {
        x_win++;
    } else if (winner == 'O') {
        o_win++;
    } else if (winner == 'T') {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    out << "Game History:\n";
    int game_number = 1;
    
    for (const auto& game : manager.games) {
        out << "Game " << game_number << ":\n";
        out << *game << "\n";
        game_number++;
    }
    
    out << "X wins: " << manager.x_win << "\n";
    out << "O wins: " << manager.o_win << "\n";
    out << "Ties: " << manager.ties << "\n";
    
    return out;
}