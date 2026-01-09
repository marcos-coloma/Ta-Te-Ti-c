#include <stdio.h>
#include "game.h"
#include "board.h"

static void game_start(void);
static void game_loop(void);
static void game_player_turn(void);
static void game_get_move(void);
static void game_apply_move(void);



void game_run(void) {
    printf("Starting Tic-Tac-Toe...\n");

    game_start();
    game_loop();

    printf("Game finished.\n");
}


static void game_start(void) {
    printf("[game_start] Initializing game...\n");
}


static void game_loop(void) {
    printf("[game_loop] Entering main loop...\n");

    // por ahora una sola iteración
    game_player_turn();
}

static void game_player_turn(void) {
    printf("[game_player_turn] Player's turn\n");

    game_get_move();
    game_apply_move();
}


static void game_get_move(void) {
    printf("[game_get_move] Getting player input...\n");
}

static void game_apply_move(void) {
    printf("[game_apply_move] Applying move to board...\n");
}
