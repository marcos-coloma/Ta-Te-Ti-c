#include <stdio.h>
#include "game.h"
#include "board.h"
#include "input.h"
#include "messages.h"

static GameMode game_menu(void);
static void game_start(Board *board);
static void pvp_game_loop(Board *board, char starting_player);
static void pvc_game_loop(Board *board, char human_player);
static int game_end(void);

static char game_choose_starting_player(void);

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

        char starting_player = game_choose_starting_player();

        switch (mode) {
            case GAME_PVP:
                pvp_game_loop(&board, starting_player);
                break;

            case GAME_PVC:
                pvc_game_loop(&board, starting_player);
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

static char game_choose_starting_player(void) {
    int choice;

    while (1) {
        msg_choose_player();
        int_number_input(&choice);

        if (choice == 1) return 'X';
        if (choice == 2) return 'O';

        input_error();
    }
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

static void pvp_game_loop(Board *board, char starting_player) {

    char current_player = starting_player;
    int running = 1;

    while (running) {
        running = game_player_turn(board, current_player);
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

static void pvc_game_loop(Board *board, char human_player) {

    char cpu_player = (human_player == 'X') ? 'O' : 'X';
    char current_player = 'X';
    int running = 1;

    while (running) {

        if (current_player == human_player) {
            running = game_player_turn(board, human_player);
        } 
        else {
            msg_cpu_turn(cpu_player);
            //not finished
            msg_not_implemented();
            return;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }
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


