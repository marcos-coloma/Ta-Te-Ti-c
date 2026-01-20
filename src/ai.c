#include <stdlib.h>
#include "ai.h"

void cpu_easy(Board *board, char cpu_player) {
    int row, col;
    do {
        row = rand() % board->size;
        col = rand() % board->size;
    } while (!board_is_empty(board, row, col));

    board_place(board, row, col, cpu_player);
}

void cpu_normal(Board *board, char cpu_player) {
    //sin hacer
    cpu_easy(board, cpu_player);
}