#include <stdlib.h>
#include "ai.h"

static int try_move(Board *board, int row, int col, char player);

//--------------------------------------------------------//

void cpu_normal(Board *board, char cpu_player) {
    int row, col;
    do {
        row = rand() % board->size;
        col = rand() % board->size;
    } while (!board_is_empty(board, row, col));

    board_place(board, row, col, cpu_player);
}

//--------------------------------------------------------//

void cpu_hard(Board *board, char cpu_player) {
    char human = (cpu_player == 'X') ? 'O' : 'X';
    int size = board->size;

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (try_move(board, r, c, cpu_player)) {
                board_place(board, r, c, cpu_player);
                return;
            }
        }
    }

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (try_move(board, r, c, human)) {
                board_place(board, r, c, cpu_player);
                return;
            }
        }
    }

    cpu_normal(board, cpu_player);
}

static int try_move(Board *board, int row, int col, char player) {
    int index = row * board->size + col;

    if (board->cells[index] != '.')
        return 0;

    board->cells[index] = player;
    int win = board_check_winner(board, player);
    board->cells[index] = '.';

    return win;
}
