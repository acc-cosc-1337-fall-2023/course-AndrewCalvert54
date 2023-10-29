#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe();
    void start_game(std::string first_player);
    bool mark_board(int position);
    std::string get_player() const;
    std::string get_winner() const;
    bool game_over();
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);

private:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;

    bool check_board_full() const;
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_next_player();
    void set_winner();
};

#endif