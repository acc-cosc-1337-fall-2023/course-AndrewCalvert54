#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"  // Include the base TicTacToe class header
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

#include <memory>
#include <vector>

class TicTacToeManager {
public:
    TicTacToeManager();
    void save_game(std::unique_ptr<TicTacToe> game);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
    int get_x_wins() const;
    int get_o_wins() const;
    int get_ties() const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(char winner);
};

#endif