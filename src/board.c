#include <stdio.h>
#include <stdlib.h>
#include "board.h"



int board_init(Board *board, int size) {
    
    if (!board || size <= 0) {
        return 0;
    }

    board->size = size;
    board->cells = malloc(size * size * sizeof(char));

    if (!board->cells) {
        board->size = 0;
        return 0;
    }

    for (int i = 0; i < size * size; i++) {
        board->cells[i] = '.';
    }

    return 1;
}


void board_free(Board *board) {

    if (!board) {
        return;
    }

    free(board->cells);
    board->cells = NULL;
    board->size = 0;
}












void board_print(const Board *board) {
    printf("[board_print] size = %d\n", board->size);
}

/* interaction */

int board_place(Board *board, int row, int col, char symbol) {
    printf("[board_place] row=%d col=%d symbol=%c\n", row, col, symbol);

    (void)board;
    return 1;
}

int board_is_empty(const Board *board, int row, int col) {
    printf("[board_is_empty] row=%d col=%d\n", row, col);

    (void)board;
    return 1; // assume empty
}

/* helpers */
int board_in_bounds(const Board *board, int row, int col) {
    printf("[board_in_bounds] row=%d col=%d size=%d\n",
        row, col, board->size);

    return 1; // assume valid
}
