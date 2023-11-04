#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"

class TicTacToe3 : public TicTacToe {
public:
    TicTacToe3(); // Constructor for TicTacToe3

    // Override functions to check for a win in columns, rows, and diagonals
    virtual bool check_column_win() const override;
    bool check_row_win() const override;
    bool check_diagonal_win() const override;

    // Implement other member functions specific to 3x3 TicTacToe, if needed
};

#endif