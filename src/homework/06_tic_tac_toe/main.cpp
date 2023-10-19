#include <iostream>
#include "tic_tac_toe.h"

int main() {
    char play_again;

    do {
        TicTacToe game;
        string first_player;

        cout << "Welcome to Tic-Tac-Toe!\n";
        cout << "Enter the first player (X or O): ";
        cin >> first_player;

        game.start_game(first_player);

        while (!game.game_over()) {
            int position;

            cout << "Current board:\n";
            game.display_board();

            cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            cin >> position;

            game.mark_board(position);
        }

        cout << "Game over!\n";
        game.display_board();

        string winner = game.get_winner();
        if (winner == "C") {
            cout << "It's a tie!\n";
        } else {
            cout << "Player " << winner << " wins!\n";
        }

        cout << "Play again? (Y/N): ";
        cin >> play_again;
    } while (play_again == 'Y' || play_again == 'y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}