#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Test win by row") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by column") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);

    REQUIRE(game.get_winner() == "X");
}

// Test win by diagonal left (top-left to bottom-right)
TEST_CASE("Test win by diagonal left") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(6);
    game.mark_board(9);

    REQUIRE(game.get_winner() == "X");
}

// Test win by diagonal right (top-right to bottom-left)
TEST_CASE("Test win by diagonal right") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(7);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test saving one game") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);

    TicTacToeManager manager;
    manager.save_game(game);

    int x_total, o_total, tie_total;
    manager.get_winner_total(x_total, o_total, tie_total);

    REQUIRE(x_total == 1);
    REQUIRE(o_total == 0);
    REQUIRE(tie_total == 0);
}

TEST_CASE("Test saving multiple games") {
    TicTacToeManager manager;

    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    manager.save_game(game);

    TicTacToe game2;
    game.start_game("O");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    manager.save_game(game);

    int x_total, o_total, tie_total;
    manager.get_winner_total(x_total, o_total, tie_total);

    REQUIRE(x_total == 1);
    REQUIRE(o_total == 1);
    REQUIRE(tie_total == 0);
}