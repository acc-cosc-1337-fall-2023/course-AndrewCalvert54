#include "tic_tac_toe.h"
#include <iostream>

// Constructor for TicTacToe
TicTacToe::TicTacToe(int size) : board_size(size), winner(' '), current_player('X'), pegs(size * size, " ") {
    // Initialize the board with empty spaces
    pegs = std::vector<std::string>(size * size, " ");
}

// Destructor for TicTacToe
TicTacToe::~TicTacToe() {
    // Destructor code, if any, goes here
}

// Function to check for a win in any column
bool TicTacToe::check_column_win() const {
    for (int col = 0; col < board_size; ++col) {
        if (pegs[col] != " ") {
            bool isWin = true;
            for (int row = 1; row < board_size; ++row) {
                if (pegs[row * board_size + col] != pegs[col]) {
                    isWin = false;
                    break;
                }
            }
            if (isWin) {
                return true;
            }
        }
    }
    return false;
}

// Function to check for a win in any row
bool TicTacToe::check_row_win() const {
    // Check each row for a win
    for (int row = 0; row < board_size; ++row) {
        // Calculate the starting index for each row (1, 4, 7 for a 3x3 board)
        int start_index = row * 3;

        // Check if the first peg in the row is not empty and if all pegs in the row are the same
        if (pegs[start_index] != " ") {
            bool isWin = true; // Assume a win in this row
            for (int col = 1; col < board_size; ++col) {
                if (pegs[start_index + col] != pegs[start_index]) {
                    isWin = false; // Found a different element, no win in this row
                    break;
                }
            }
            if (isWin) {
                return true; // All pegs in the row are the same, indicating a win
            }
        }
    }
    return false; // No row win
}

// Function to check for a win in any diagonal
bool TicTacToe::check_diagonal_win() const {
    // Check the main diagonal (positions 1, 5, 9 for a 3x3 board)
    if (pegs[0] != " ") {
        bool isWin = true; // Assume a win in the main diagonal
        for (int i = 1; i < board_size; ++i) {
            if (pegs[i * (board_size + 1)] != pegs[0]) {
                isWin = false; // Found a different element, no win in the main diagonal
                break;
            }
        }
        if (isWin) {
            return true; // All pegs in the main diagonal are the same, indicating a win
        }
    }

    // Check the other diagonal (positions 3, 5, 7 for a 3x3 board)
    if (pegs[2] != " ") {
        bool isWin = true; // Assume a win in the other diagonal
        for (int i = 1; i < board_size; ++i) {
            if (pegs[(i + 1) * (board_size - 1)] != pegs[2]) {
                isWin = false; // Found a different element, no win in the other diagonal
                break;
            }
        }
        if (isWin) {
            return true; // All pegs in the other diagonal are the same, indicating a win
        }
    }

    return false; // No diagonal win
}

// Function to start the game with a specific player ('X' or 'O')
void TicTacToe::start_game(char player) {
    current_player = player;
}

// Function to check if the game is over
bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        winner = current_player;
        return true; // The game is over
    }

    // Check if the board is full (a tie)
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false; // The game is not over yet
        }
    }

    // If neither player has won and the board is full, it's a tie
    winner = 'T';
    return true; // The game is over as a tie
}

// Function to mark the board at a specific position with the current player's symbol
void TicTacToe::mark_board(int position, char player) {
    // Ensure the position is within the valid range (1 to board_size^2)
    if (position < 1 || position > board_size * board_size) {
        throw std::out_of_range("Invalid position. Position must be between 1 and " + std::to_string(board_size * board_size));
    }

    // Convert the position (1-16) to row and column indices (0-3 for a 4x4 board)
    int row = (position - 1) / board_size;
    int col = (position - 1) % board_size;

    // Check if the specified position is already marked
    if (pegs[row * board_size + col] != " ") {
        throw std::invalid_argument("Position already marked. Choose an empty position.");
    }

    // Mark the board with the player's symbol at the specified position
    pegs[row * board_size + col] = std::string(1, player);
}

// Function to get the winner of the game ('X', 'O', or ' ')
char TicTacToe::get_winner() const {
    return winner;
}

// Function to display the current state of the board
void TicTacToe::display_board() const {
    for (int i = 0; i < board_size * board_size; ++i) {
        std::cout << pegs[i];
        if ((i + 1) % board_size != 0) {
            std::cout << " | ";
        } else if (i < board_size * board_size - 1) {
            std::cout << "\n---------\n";
        }
    }
    std::cout << std::endl;
}

// Overloaded stream output operator for TicTacToe
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    game.display_board();
    return out;
}

// Overloaded stream input operator for TicTacToe
std::istream& operator>>(std::istream& in, TicTacToe& game) {
    int position;
    std::cout << "Player " << game.current_player << ", enter your move (1-" << game.board_size * game.board_size << "): ";
    in >> position;

    // Check if the input position is valid (within the board size and not already marked)
    if (position >= 1 && position <= game.board_size * game.board_size && game.pegs[position - 1] == " ") {
        // Update the game board with the current player's symbol at the specified position
        game.mark_board(position - 1, game.current_player);

        // Switch to the next player for the next turn
        game.current_player = (game.current_player == 'X') ? 'O' : 'X';
    } else {
        // Invalid move, ask the same player for another move
        std::cout << "Invalid move! Try again." << std::endl;
    }

    return in;
}

void TicTacToe::set_winner(char winner){
    this->winner = winner;
}

char TicTacToe::get_player() const {
    return current_player;
}