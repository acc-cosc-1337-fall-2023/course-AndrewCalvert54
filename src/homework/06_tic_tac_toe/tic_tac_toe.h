#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>

class TicTacToe {
public:
    // Constructor that takes the board size as a parameter
    TicTacToe(int size);

    // Destructor
    ~TicTacToe();

    // Virtual functions for checking wins in columns, rows, and diagonals
    virtual bool check_column_win() const;
    virtual bool check_row_win() const;
    virtual bool check_diagonal_win() const;

    // Start a new game with the specified player
    void start_game(char player);

    // Check if the game is over
    bool game_over();

    // Mark the board at a given position with the current player's symbol
    void mark_board(int position, char player);

    // Get the winner of the game
    char get_winner() const;

    // Display the current state of the board
    void display_board() const;

    // Friend functions for streaming input and output
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

    void set_winner(char winner);

    char get_player() const;

protected:
    // Private functions for board-specific logic
    int board_size;       // Size of the board (e.g., 3 or 4)
    mutable char winner;  // Stores the winner of the game
    char current_player;
    std::vector<std::string> pegs;  // Represents the game board as a vector of strings
};

#endif