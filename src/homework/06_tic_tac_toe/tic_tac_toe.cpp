#include "tic_tac_toe.h"

TicTacToe::TicTacToe() : player("X"), pegs(9, " "), winner(" ") {}

bool TicTacToe::game_over() {
    if (check_board_full() || check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    return false;
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

string TicTacToe::get_player(){
    return player;
}

void TicTacToe::display_board(){
    cout << "  " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "\n";
    cout << " -----------\n";
    cout << "  " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "\n";
    cout << " -----------\n";
    cout << "  " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n";
}

string TicTacToe::get_winner() {
    if (check_board_full() && !check_column_win() && !check_row_win() && !check_diagonal_win()) {
        return "Tie";
    } else {
        return winner;
    }
}

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

bool TicTacToe::check_column_win() {
    for (int col = 0; col < 3; col++) {
        if (pegs[col] == pegs[col + 3] && pegs[col + 3] == pegs[col + 6] && pegs[col] != " ") {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win() {
    for (int i = 0; i < 9; i += 3) {
        if (pegs[i] == pegs[i + 1] && pegs[i + 1] == pegs[i + 2] && pegs[i] != " ") {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() {
    return (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
           (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " ");
}

void TicTacToe::clear_board() {
    for (std::string& peg : pegs) {
        peg = " ";
    }
    winner = " ";
}