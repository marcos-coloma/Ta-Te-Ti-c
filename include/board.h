#ifndef BOARD_H
#define BOARD_H

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

#define PRINT_X printf(RED "X" RESET)
#define PRINT_O printf(BLUE "O" RESET)

typedef struct {
    char *cells;
    int size;
} Board;

/* lifecycle */
int board_init(Board *board, int size);
void board_free(Board *board);

/* visualization */
void board_print(const Board *board);

/* interaction */
int board_place(Board *board, int row, int col, char symbol);
int board_is_empty(const Board *board, int row, int col);

/* helpers */
int board_in_bounds(const Board *board, int row, int col);

/* results */
int board_check_winner(const Board *board, char player);
int board_is_full(const Board *board);

#endif