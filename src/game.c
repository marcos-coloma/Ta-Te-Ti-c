#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"
#include "messages.h"

static void game_start(Board *board);
static void game_loop(Board *board);
static int game_player_turn(Board *board, char player);
static void game_get_move(int *row, int *col);
static int game_apply_move(Board *board, int row, int col, char player);



void game_run(void) {

    msg_title();

    Board board;

    game_start(&board);
    game_loop(&board);

}

static void game_start(Board *board) {
    int size = 3;

    msg_game_start(size);

    board_init(board, size);
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

    int row, col;

    msg_player_turn(player);

    do {
        game_get_move(&row, &col);
    } while (!game_apply_move(board, row, col, player));

    board_print(board);
    return 1;
}

static void game_get_move(int *row, int *col) {

    msg_get_move();

    printf("Enter row: ");
    int_number_input(row);

    printf("Enter column: ");
    int_number_input(col);

    (*row)--;
    (*col)--;
}

static int game_apply_move(Board *board, int row, int col, char player) {
    return board_place(board, row, col, player);
}