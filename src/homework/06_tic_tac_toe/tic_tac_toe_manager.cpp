#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game) {
    games.push_back(game);
    update_winner_count(game.get_winner());
}

void TicTacToeManager::get_winner_total(int& x_total, int& o_total, int& tie_total) const {
    x_total = x_win;
    o_total = o_win;
    tie_total = ties;
}

void TicTacToeManager::update_winner_count(const std::string& winner) {
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else if (winner == "Tie") {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    for (const auto& game : manager.games) {
        out << game;
        out << "X wins: " << manager.x_win << ", O wins: " << manager.o_win << ", Ties: " << manager.ties << "\n";
    }
    return out;
}