#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;

class TicTacToe {
public:
    TicTacToe();
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player();
    void display_board();
    string get_winner();
    bool check_column_win();
    
private:
    string player;
    vector<string> pegs;
    string winner;

    void set_winner();
    void set_next_player();
    bool check_board_full();
    
    bool check_row_win();
    bool check_diagonal_win();
    void clear_board();
};

#endif