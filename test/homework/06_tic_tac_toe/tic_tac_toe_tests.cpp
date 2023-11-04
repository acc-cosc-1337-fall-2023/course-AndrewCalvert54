#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <iostream>

TEST_CASE("Test diagonal win from the left in TicTacToe3") {
    TicTacToe3 game;
    game.start_game('X'); // Use character 'X' instead of string "X"

    // X wins by filling the diagonal from the left
    game.mark_board(1, 'X'); // X
    game.mark_board(2, 'O'); // O
    game.mark_board(5, 'X'); // X
    game.mark_board(7, 'O'); // O
    game.mark_board(9, 'X'); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'X'); // 'X' is the winner
}

TEST_CASE("Test saving one games in TicTacToeManager 3x3 diagonal_win_right_to_left") {
    TicTacToeManager manager;

    TicTacToe3 game;
    game.start_game('X'); // Use character 'X' instead of string "X"

    // X wins by filling the diagonal from the right
    game.mark_board(3, 'X'); // X
    game.mark_board(2, 'O'); // O
    game.mark_board(5, 'X'); // X
    game.mark_board(4, 'O'); // O
    game.mark_board(7, 'X'); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'X'); // 'X' is the winner

    
    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe3 object into it
    std::unique_ptr<TicTacToe> game_ptr = std::make_unique<TicTacToe3>(std::move(game));

    // Save the first game to the manager
    manager.save_game(std::move(game_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 0);
    REQUIRE(manager.get_ties() == 0);
}

TEST_CASE("Test saving three games in TicTacToeManager 3x3 row_win, column_win, tie") {
    TicTacToeManager manager;

    // Create and play the first TicTacToe3 game, column
    TicTacToe3 game1;
    game1.start_game('X');
    game1.mark_board(1, 'X'); // X
    game1.mark_board(2, 'O'); // O
    game1.mark_board(4, 'X'); // X
    game1.mark_board(5, 'O'); // O
    game1.mark_board(7, 'X'); // X

    REQUIRE(game1.game_over() == true);
    REQUIRE(game1.get_winner() == 'X');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe3 object into it
    std::unique_ptr<TicTacToe> game1_ptr = std::make_unique<TicTacToe3>(std::move(game1));

    // Save the first game to the manager
    manager.save_game(std::move(game1_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 0);
    REQUIRE(manager.get_ties() == 0);

    // Create and play the second TicTacToe3 game, row
    TicTacToe3 game2;
    game2.start_game('O');
    game2.mark_board(1, 'O'); // X
    game2.mark_board(4, 'X'); // O
    game2.mark_board(2, 'O'); // X
    game2.mark_board(5, 'X'); // O
    game2.mark_board(3, 'O'); // X

    REQUIRE(game2.game_over() == true);
    REQUIRE(game2.get_winner() == 'O');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe3 object into it
    std::unique_ptr<TicTacToe> game2_ptr = std::make_unique<TicTacToe3>(std::move(game2));

    // Save the second game to the manager
    manager.save_game(std::move(game2_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 1);
    REQUIRE(manager.get_ties() == 0);

    // Create and play the third TicTacToe3 game, tie
    TicTacToe3 game3;
    game3.start_game('X');
    game3.mark_board(1, 'X'); // X
    game3.mark_board(2, 'O'); // O
    game3.mark_board(3, 'X'); // X
    game3.mark_board(4, 'O'); // O
    game3.mark_board(6, 'X'); // X
    game3.mark_board(5, 'O');
    game3.mark_board(7, 'X');
    game3.mark_board(9, 'O');
    game3.mark_board(8, 'X');

    REQUIRE(game3.game_over() == true);
    REQUIRE(game3.get_winner() == 'T');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe3 object into it
    std::unique_ptr<TicTacToe> game3_ptr = std::make_unique<TicTacToe3>(std::move(game3));

    // Save the third game to the manager
    manager.save_game(std::move(game3_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 1);
    REQUIRE(manager.get_ties() == 1);

    
}


TEST_CASE("Test diagonal win from the left in TicTacToe4") {
    TicTacToeManager manager;

    // Create a TicTacToe4 game and play some moves
    TicTacToe4 game;
    game.mark_board(1, 'X'); // X
    game.mark_board(2, 'O'); // O
    game.mark_board(6, 'X'); // X
    game.mark_board(7, 'O'); // O
    game.mark_board(11, 'X'); // X
    game.mark_board(8, '0'); // X

    REQUIRE(game.game_over() == false);

    game.mark_board(16, 'X'); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'X');

}

TEST_CASE("Test saving one game in TicTacToeManager 4x4 diagonal_right") {
    TicTacToeManager manager;

    // Create a TicTacToe3 game and play some moves
    TicTacToe4 game;
    game.mark_board(4, 'X'); // X
    game.mark_board(3, 'O'); // O
    game.mark_board(7, 'X'); // X
    game.mark_board(6, 'O'); // O
    game.mark_board(10, 'X'); // X
    game.mark_board(5, '0'); // X
    game.mark_board(13, 'X'); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'X');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe3 object into it
    std::unique_ptr<TicTacToe> game_ptr = std::make_unique<TicTacToe4>(std::move(game));

    // Save the game to the manager
    manager.save_game(std::move(game_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 0);
    REQUIRE(manager.get_ties() == 0);
}

TEST_CASE("Test saving three games in TicTacToeManager 4x4 column_win, row_win, tie") {
    TicTacToeManager manager;

    // Create and play the first TicTacToe4 game
    TicTacToe4 game1;
    game1.start_game('X');
    game1.mark_board(1, 'X'); // X
    game1.mark_board(2, 'O'); // O
    game1.mark_board(5, 'X'); // X
    game1.mark_board(6, 'O'); // O
    game1.mark_board(9, 'X'); // X
    game1.mark_board(10, 'O'); // O
    game1.mark_board(13, 'X'); // X

    REQUIRE(game1.game_over() == true);
    REQUIRE(game1.get_winner() == 'X');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe4 object into it
    std::unique_ptr<TicTacToe> game1_ptr = std::make_unique<TicTacToe4>(std::move(game1));

    // Save the first game to the manager
    manager.save_game(std::move(game1_ptr));

    // Create and play the second TicTacToe4 game
    TicTacToe4 game2;
    game2.start_game('O');
    game2.mark_board(1, 'O'); // X
    game2.mark_board(5, 'X'); // O
    game2.mark_board(2, 'O'); // X
    game2.mark_board(6, 'X'); // O
    game2.mark_board(3, 'O'); // X
    game2.mark_board(7, 'X'); // O
    game2.mark_board(4, 'O'); // X

    REQUIRE(game2.game_over() == true);
    REQUIRE(game2.get_winner() == 'O');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe4 object into it
    std::unique_ptr<TicTacToe> game2_ptr = std::make_unique<TicTacToe4>(std::move(game2));

    // Save the second game to the manager
    manager.save_game(std::move(game2_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 1);
    REQUIRE(manager.get_ties() == 0);

    // Create and play the third TicTacToe4 game
    TicTacToe4 game3;
    game3.start_game('O');
    game3.mark_board(1, 'O'); // X
    game3.mark_board(2, 'X'); // O
    game3.mark_board(3, 'O'); // X
    game3.mark_board(4, 'X'); // O
    game3.mark_board(5, 'O'); // X
    game3.mark_board(6, 'X'); // O
    game3.mark_board(7, 'O'); // X
    game3.mark_board(8, 'X'); // X
    game3.mark_board(9, 'O'); // X
    game3.mark_board(10, 'X'); // X
    game3.mark_board(11, 'O'); // X
    game3.mark_board(12, 'X'); // X
    game3.mark_board(14, 'O'); // X
    game3.mark_board(15, 'X'); // X
    game3.mark_board(16, 'O'); // X
    game3.mark_board(13, 'X'); // X

    REQUIRE(game3.game_over() == true);
    REQUIRE(game3.get_winner() == 'T');

    // Create a std::unique_ptr<TicTacToe> and move the TicTacToe4 object into it
    std::unique_ptr<TicTacToe> game3_ptr = std::make_unique<TicTacToe4>(std::move(game3));

    // Save the second game to the manager
    manager.save_game(std::move(game3_ptr));

    REQUIRE(manager.get_x_wins() == 1);
    REQUIRE(manager.get_o_wins() == 1);
    REQUIRE(manager.get_ties() == 1);
}