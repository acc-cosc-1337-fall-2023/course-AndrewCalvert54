#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test first player set to X", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(3); // X
    game.mark_board(4); // O
    game.mark_board(5); // X
    game.mark_board(7); // O
    game.mark_board(6); // X
    game.mark_board(9); // O
    game.mark_board(8); // X (all slots are selected now)

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(4); // X
    game.mark_board(3); // O
    game.mark_board(7); // X

    REQUIRE(game.check_column_win() == true);
}

TEST_CASE("Test win by second column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(2); // X
    game.mark_board(1); // O
    game.mark_board(5); // X
    game.mark_board(4); // O
    game.mark_board(8); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3); // X
    game.mark_board(1); // O
    game.mark_board(6); // X
    game.mark_board(4); // O
    game.mark_board(9); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(4); // O
    game.mark_board(2); // X
    game.mark_board(5); // O
    game.mark_board(3); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(4); // X
    game.mark_board(1); // O
    game.mark_board(5); // X
    game.mark_board(2); // O
    game.mark_board(6); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); // X
    game.mark_board(1); // O
    game.mark_board(8); // X
    game.mark_board(2); // O
    game.mark_board(9); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(5); // X
    game.mark_board(4); // O
    game.mark_board(9); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); // X
    game.mark_board(1); // O
    game.mark_board(5); // X
    game.mark_board(2); // O
    game.mark_board(3); // X

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test for a tie game", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(3); // X
    game.mark_board(4); // O
    game.mark_board(5); // X
    game.mark_board(7); // O
    game.mark_board(6); // X
    game.mark_board(9); // O
    game.mark_board(8); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "Tie"); // Expecting "Tie" for a tie game
}