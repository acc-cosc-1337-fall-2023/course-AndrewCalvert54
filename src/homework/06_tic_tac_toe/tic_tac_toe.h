//h
#include <iostream>
#include <vector>
#include <string>


using std::string;
using std::vector;
using std::cout;
using std::cin;

class TicTacToe{

    public:
        TicTacToe();
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        void display_board() const;
         void set_next_player();
        bool check_board_full();
        void clear_board();
        
    private:
        string player;
        vector<std::string> pegs;

};