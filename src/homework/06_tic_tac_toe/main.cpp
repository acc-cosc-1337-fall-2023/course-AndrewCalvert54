#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main() {
    TicTacToeManager manager;
    char choice;

    do {
        TicTacToe game;
        game.start_game("X");

        do {
            int position;
            std::cout << "Player " << game.get_player() << ", enter your position (1-9): ";
            std::cin >> position;

            if (game.mark_board(position)) {
                std::cout << game;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        } while (!game.game_over());

        manager.save_game(game);

        int x_total, o_total, tie_total;
        manager.get_winner_total(x_total, o_total, tie_total);

        std::cout << "X wins: " << x_total << ", O wins: " << o_total << ", Ties: " << tie_total << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << manager;

    return 0;
}