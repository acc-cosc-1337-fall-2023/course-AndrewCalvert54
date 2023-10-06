//cpp
#include "tic_tac_toe.h"

TicTacToe::TicTacToe() : player("X"), pegs(9, " ") {}


bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(string first_player) {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
    } else {
        cout << "Invalid first player. Defaulting to X.\n";
        player = "X";
    }
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        set_next_player();
    }
}

string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    cout << "  " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "\n";
    cout << " -----------\n";
    cout << "  " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "\n";
    cout << " -----------\n";
    cout << "  " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    for (string& peg : pegs) {
        peg = " ";
    }
}