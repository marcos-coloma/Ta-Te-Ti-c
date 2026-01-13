#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"

static void game_start(Board *board);
static void game_loop(Board *board);
static int game_player_turn(Board *board, char player);
static void game_get_move(int *row, int *col);
static int game_apply_move(Board *board, int row, int col, char player);



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

    char current_player = 'X';
    int running = 1;

    while (running) {
        running = game_player_turn(board, current_player);
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

static int game_player_turn(Board *board, char player) {
    printf("[game_player_turn] Player %c turn\n", player);

    int row, col;

    game_get_move(&row, &col);

    if (!game_apply_move(board, row, col, player)) {
        printf("Invalid move. Try again.\n");
        return 1; // mismo jugador
    }

    board_print(board);
    return 1;
}

static void game_get_move(int *row, int *col) {
    printf("[game_get_move] Getting player input...\n");

    printf("Enter row: ");
    int_number_input(row);

    printf("Enter column: ");
    int_number_input(col);
}

static int game_apply_move(Board *board, int row, int col, char player) {
    printf("[game_apply_move] Applying move to board...\n");
    return board_place(board, row, col, player);
}