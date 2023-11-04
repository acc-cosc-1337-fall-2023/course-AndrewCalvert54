#include "tic_tac_toe_4.h"

TicTacToe4::TicTacToe4() : TicTacToe(4) {
    // Additional initialization specific to 4x4 TicTacToe, if any
}

bool TicTacToe4::check_row_win() const {
    // Check for a win in any row (4x4 specific)
    for (int row = 0; row < 4; ++row) {
        // Calculate the starting index for each row (1, 5, 9, 13 for a 4x4 board)
        int start_index = row * 4 + 1;

        // Check if the first peg in the row is not empty and if all four pegs in the row are the same
        if (pegs[start_index - 1] != " " && pegs[start_index - 1] == pegs[start_index] &&
            pegs[start_index] == pegs[start_index + 1] && pegs[start_index + 1] == pegs[start_index + 2]) {
            return true;
        }
    }
    return false; // No row win
}

bool TicTacToe4::check_column_win() const {
    // Check for a win in any column (4x4 specific)
    for (int col = 0; col < 4; ++col) {
        // Calculate the starting index for each column (1, 2, 3, 4 for a 4x4 board)
        int start_index = col + 1;

        // Check if the first peg in the column is not empty and if all four pegs in the column are the same
        if (pegs[start_index - 1] != " " && pegs[start_index - 1] == pegs[start_index + 3] &&
            pegs[start_index + 3] == pegs[start_index + 7] && pegs[start_index + 7] == pegs[start_index + 11]) {
            return true;
        }
    }
    return false; // No column win
}

bool TicTacToe4::check_diagonal_win() const {
    // Check for a win in any diagonal (4x4 specific)
    // Check the main diagonal (1, 6, 11, 16 for a 4x4 board)
    if (pegs[0] != " " && pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15]) {
        return true;
    }

    // Check the other diagonal (4, 7, 10, 13 for a 4x4 board)
    if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12]) {
        return true;
    }

    return false; // No diagonal win
}

// Implement other member functions specific to 4x4 TicTacToe, if needed