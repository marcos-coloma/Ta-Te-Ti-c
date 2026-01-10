#include <stdio.h>
#include "game.h"
#include "board.h"

static void game_start(Board *board);
static void game_loop(Board *board);
static void game_player_turn(Board *board);
static void game_get_move(void);
static void game_apply_move(Board *board);



void game_run(void) {

    Board board;

    game_start(&board);
    game_loop(&board);

}


static void game_start(Board *board) {
    printf("[game_start] Initializing game...\n");

    board_init(board, 3);
    board_print(board);
}


static void game_loop(Board *board) {
    printf("[game_loop] Entering main loop...\n");

    int running = 1;

    while (running) {
        game_player_turn(board);
        running = 0; // temporal
    }
}





static void game_player_turn(Board *board) {
    printf("[game_player_turn] Player's turn\n");

    game_get_move();
    game_apply_move(board);
}


static void game_get_move(void) {
    printf("[game_get_move] Getting player input...\n");
}

static void game_apply_move(Board *board) {
    printf("[game_apply_move] Applying move to board...\n");
}
