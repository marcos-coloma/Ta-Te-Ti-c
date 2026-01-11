#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"

static void game_start(Board *board);
static void game_loop(Board *board);
static void game_player_turn(Board *board);
static void game_get_move(int *row, int *col);
static void game_apply_move(Board *board, int row, int col);



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

    int row, col;

    game_get_move(&row, &col);
    game_apply_move(board, row, col);
    board_print(board);
}


static void game_get_move(int *row, int *col) {
    printf("[game_get_move] Getting player input...\n");

    printf("Enter row: ");
    int_number_input(row);

    printf("Enter column: ");
    int_number_input(col);
}


static void game_apply_move(Board *board, int row, int col) {
    printf("[game_apply_move] Applying move to board...\n");

    board_place(board, row, col, 'X');
}
