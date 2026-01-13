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

    if (!board || !board->cells) {
        msg_invalid_board();
        return;
    }

    msg_show_board();

    for (int row = 0; row < board->size; row++) {
        for (int col = 0; col < board->size; col++) {
            int index = row * board->size + col;
            printf("%c ", board->cells[index]);
        }
        printf("\n");
    }

    msg_after_board();
}

int board_place(Board *board, int row, int col, char symbol) {
    if (!board || !board->cells) {
        return 0;
    }

    if (!board_in_bounds(board, row, col)) {
        msg_board_in_bounds();
        return 0;
    }

    if (!board_is_empty(board, row, col)) {
        msg_board_is_empty();
        return 0;
    }

    int index = row * board->size + col;
    board->cells[index] = symbol;

    return 1;
}

int board_is_empty(const Board *board, int row, int col) {
    if (!board || !board->cells) return 0;

    if (!board_in_bounds(board, row, col)) return 0;

    int index = row * board->size + col;
    return board->cells[index] == '.';
}

int board_in_bounds(const Board *board, int row, int col) {
    if (!board) return 0;

    if (row < 0 || row >= board->size) return 0;
    if (col < 0 || col >= board->size) return 0;

    return 1;
}
