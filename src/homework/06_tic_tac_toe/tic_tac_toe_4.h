#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe {
public:
    TicTacToe4(); // Constructor for TicTacToe4

    // Override functions to check for a win in columns, rows, and diagonals
    bool check_column_win() const override;
    bool check_row_win() const override;
    bool check_diagonal_win() const override;

    // Implement other member functions specific to 4x4 TicTacToe, if needed
};

#endif