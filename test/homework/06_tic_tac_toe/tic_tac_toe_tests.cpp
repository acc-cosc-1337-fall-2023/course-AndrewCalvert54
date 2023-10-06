#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over in a tie", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(2); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(3); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(4); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(5); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(7); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(6); // X
    REQUIRE(game.game_over() == false);

    game.mark_board(9); // O
    REQUIRE(game.game_over() == false);

    game.mark_board(8); // X (all slots are selected now)
    REQUIRE(game.game_over() == true);
}