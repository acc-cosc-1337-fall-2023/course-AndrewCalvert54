#include "tic_tac_toe.h"

TicTacToe::TicTacToe() : pegs(9, " "), player("X"), winner("") {}

void TicTacToe::start_game(std::string first_player) {
    player = (first_player == "X" || first_player == "O") ? first_player : "X";
    winner = "";
    pegs.assign(9, " ");
}

bool TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= 9 && pegs[position - 1] == " " && !game_over()) {
        pegs[position - 1] = player;
        if (check_column_win() || check_row_win() || check_diagonal_win()) {
            set_winner();
        } else if (check_board_full() && winner.empty()) {
            winner = "Tie";
        } else {
            set_next_player();
        }
        return true;
    }
    return false;
}

std::string TicTacToe::get_player() const {
    return player;
}

std::string TicTacToe::get_winner() const {
    return winner;
}

bool TicTacToe::game_over() {
    if (check_board_full() || check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    return false;
}

bool TicTacToe::check_board_full() const {
    for (const auto& peg : pegs) {
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

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

void TicTacToe::set_winner() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        winner = player;
    } else if (check_board_full() && winner.empty()) {
        winner = "Tie";
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    out << " " << game.pegs[0] << " | " << game.pegs[1] << " | " << game.pegs[2] << " \n";
    out << " -----------\n";
    out << " " << game.pegs[3] << " | " << game.pegs[4] << " | " << game.pegs[5] << " \n";
    out << " -----------\n";
    out << " " << game.pegs[6] << " | " << game.pegs[7] << " | " << game.pegs[8] << " \n";
    return out;
}