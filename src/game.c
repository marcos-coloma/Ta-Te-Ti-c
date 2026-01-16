#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"
#include "messages.h"

static GameMode game_menu(void);
static void game_start(Board *board);
static void pvp_game_loop(Board *board);
static void pvc_game_loop(Board *board);
static int game_end(void);

static int game_player_turn(Board *board, char player);
static void game_get_move(int *row, int *col);
static int game_apply_move(Board *board, int row, int col, char player);


//-------------------------------------------------//

void game_run(void) {

    while (1) {

        msg_title();

        GameMode mode = game_menu();

        if (mode == GAME_EXIT) {
            break;
        }

        Board board;

        game_start(&board);

        switch (mode) {
            case GAME_PVP:
                pvp_game_loop(&board);
                break;

            case GAME_PVC:
                pvc_game_loop(&board);
                break;

            default:
                input_error();
                break;
        }

        if (!game_end()) {
            break;
        }
    }
}

static GameMode game_menu(void) {
    int choice;

    while (1) {
        msg_game_menu();
        int_number_input(&choice);

        if (choice >= 0 && choice <= 2) {
            return (GameMode)choice;
        }

        input_error();
    }
}

static void game_start(Board *board) {
    int size;
    msg_board_size();


    do {
        int_number_input(&size);

        if (size < 3 || size > 7) {
            input_error(); 
        }
        
    } while (size < 3 || size > 7);


    msg_game_start(size);
    board_init(board, size);
    board_print(board);
}

static int game_end(void) {
    int choice;

    do {
        msg_end();
        int_number_input(&choice);

        if (choice != 0 && choice != 1) {
            input_error();
        }

    } while (choice != 0 && choice != 1);

    return choice == 1;
}

//-------------------------------------------------//

static void pvp_game_loop(Board *board) {

    char current_player = 'X';
    int running = 1;

    while (running) {
        running = game_player_turn(board, current_player);
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

static void pvc_game_loop(Board *board){
    (void)board;
    msg_not_implemented();
}

//-------------------------------------------------//

static int game_player_turn(Board *board, char player) {

    int row, col;

    msg_player_turn(player);

    do {
        game_get_move(&row, &col);
    } while (!game_apply_move(board, row, col, player));

        board_print(board);
    
    if (board_check_winner(board, player)) {
        msg_player_wins(player);
        return 0;
    }

    if (board_is_full(board)) {
        msg_game_draw();
        return 0;
    }

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


