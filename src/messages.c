#include <stdio.h>
#include "messages.h"

//---------------------------//
// Error messages
//---------------------------//

void input_error(void) {
    printf("Invalid number. Remember to enter an integer within the allowed range\n");
    printf("Please try again: ");
}

void msg_invalid_board(void) {
    printf("\n[Error] The game board is not initialized properly.\n");
}

void msg_board_in_bounds(void) {
    printf("Invalid move: position is outside the board.\n");
}

void msg_board_is_empty(void) {
    printf("Invalid move: this cell is already occupied.\n");
}


//---------------------------//
// UI / Title messages
//---------------------------//

void msg_title(void) {
    printf("\n\n\n\n\n");
    printf("==============================\n");
    printf(" Welcome to Tic-Tac-Toe in C!\n");
    printf("==============================\n\n");
}

void msg_game_menu(void){
    printf("Select game mode:\n");
    printf("\n");
    printf("0 - Player vs Player\n");
    printf("1 - Player vs Computer\n");
    printf("2 - Exit\n");
    printf("\n");
    printf("Your choice: ");
}

void msg_game_start(int size) {
    printf("Starting game (%dx%d board)\n\n", size, size);
}

void msg_board_size(void){
    printf("-You can choose the size of your board.\n");
    printf("-The size of the board can be between 3 and 7\n\n");
    printf("Enter the board size: ");
}

void msg_choose_player(void) {
    printf("\nChoose starting player:\n");
    printf("0) X\n");
    printf("1) O\n");
}

void msg_choose_difficulty(void) {
    printf("\nChoose AI difficulty:\n");
    printf("0) Easy   (random moves)\n");
    printf("1) Hard   (difficult to beat)\n");
}


//---------------------------//
// Player / Turn messages
//---------------------------//

void msg_player_turn(char player) {
    printf("\n--- Player %c ---\n", player);
}

void msg_get_move(void) {
    printf("\nChoose a row and a column to place your mark.\n");
}


//---------------------------//
// Board display messages
//---------------------------//

void msg_show_board(void) {
    printf("\n=== Current Board ===\n\n");
}

void msg_after_board(void) {
    printf("\n=====================\n");
}


//---------------------------//
// CPU / AI messages
//---------------------------//

void msg_cpu_turn(char cpu_player) {
    printf("\nCPU turn (%c)\n", cpu_player);
}


//---------------------------//
// End of game messages
//---------------------------//

void msg_player_wins(char player) {
    printf("\nPlayer %c wins! Congratulations!\n", player);
}

void msg_game_draw(void) {
    printf("\nIt's a draw!\n");
}

void msg_end(void){
    printf("\n\n\n");
    printf("==============================\n");
    printf(" Match finished!\n");
    printf("==============================\n");
    printf("Play again?\n");
    printf("1 - Yes\n");
    printf("0 - Exit\n");
    printf("Your choice: ");
}
