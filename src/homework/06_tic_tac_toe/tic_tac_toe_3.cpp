#include "tic_tac_toe_3.h"

TicTacToe3::TicTacToe3() : TicTacToe(3) {
    // Additional initialization specific to 3x3 TicTacToe, if any
}

bool TicTacToe3::check_column_win() const {
    // Check for a win in any column (3x3 specific)
    for (int col = 0; col < 3; ++col) {
        // Calculate the starting index for each column (1, 2, 3 for a 3x3 board)
        int start_index = col + 1;

        // Check if the first peg in the column is not empty and if all three pegs in the column are the same
        if (pegs[start_index - 1] != " " && pegs[start_index - 1] == pegs[start_index + 2] && pegs[start_index + 2] == pegs[start_index + 5]) {
            return true;
        }
    }
    return false; // No column win
}

// Override function to check for a win in any row (3x3 specific)
bool TicTacToe3::check_row_win() const {
    // Check for a win in any row (3x3 specific)
    for (int row = 0; row < 3; ++row) {
        // Calculate the starting index for each row (1, 4, 7 for a 3x3 board)
        int start_index = row * 3 + 1;

        // Check if the first peg in the row is not empty and if all three pegs in the row are the same
        if (pegs[start_index - 1] != " " && pegs[start_index - 1] == pegs[start_index] && pegs[start_index] == pegs[start_index + 1]) {
            return true;
        }
    }
    return false; // No row win
}

bool TicTacToe3::check_diagonal_win() const {
    // Check the main diagonal (positions 1, 5, 9 for a 3x3 board)
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) {
        return true;
    }

    // Check the other diagonal (positions 3, 5, 7 for a 3x3 board)
    if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]) {
        return true;
    }

    return false; // No diagonal win
}


// Implement other member functions specific to 3x3 TicTacToe, if needed