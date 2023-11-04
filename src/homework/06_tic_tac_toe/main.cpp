#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <memory>

int main() {
    char choice;
    TicTacToeManager manager; // Create a TicTacToeManager object to track wins

    do {
        int board_size;
        char starting_player;
        std::cout << "Choose the board size (3 or 4): ";
        std::cin >> board_size;

        std::cout << "Choose your starting player (X or O): ";
        std::cin >> starting_player;

        std::unique_ptr<TicTacToe> game;

        if (board_size == 3) {
            game = std::make_unique<TicTacToe3>();
        } else if (board_size == 4) {
            game = std::make_unique<TicTacToe4>();
        } else {
            std::cout << "Invalid board size. Please choose 3 or 4.\n";
            continue; // Restart the loop if the board size is invalid
        }

        game->start_game(starting_player);

        char player = starting_player;
        int position;
        bool valid_move;

        while (!game->game_over()) {
            std::cout << *game;
            std::cout << "Player " << player << ", enter your position (1-" << board_size * board_size << "): ";
            std::cin >> position;

            try {
                game->mark_board(position, player);
                valid_move = true;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                valid_move = false;
            }

            if (valid_move) {
                if (player == 'X') {
                    player = 'O';
                } else {
                    player = 'X';
                }
            }
        }

        std::cout << *game;
        if (game->game_over()) {
            if (game->get_winner() == starting_player) {
                std::cout << "Player " << starting_player << " wins!\n";
            } else {
                std::cout << "It's a tie!\n";
            }

            // Save the game to TicTacToeManager
            manager.save_game(std::move(game));
        }

        std::cout << manager;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;

        while (std::toupper(choice) != 'Y' && std::toupper(choice) != 'N') {
            std::cout << "Invalid choice. Please enter 'y' or 'n': ";
            std::cin >> choice;
        }
    } while (std::toupper(choice) == 'Y');

    return 0;
}