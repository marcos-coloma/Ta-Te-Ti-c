#include <stdio.h>
#include "messages.h"

void input_error(void) {
    printf("Invalid number. Remember to enter an integer within the allowed range\n");
    printf("Please try again: ");
}

void msg_title(void) {
    printf("==============================\n");
    printf(" Welcome to Tic-Tac-Toe in C!\n");
    printf("==============================\n\n");
}

void msg_game_start(int size) {
    printf("Starting game (%dx%d board)\n\n", size, size);
}

void msg_player_turn(char player) {
    printf("\n--- Player %c ---\n", player);
}

void msg_get_move(void) {
    printf("\nChoose a row and a column to place your mark.\n");;
}

void msg_invalid_board(void) {
    printf("\n[Error] The game board is not initialized properly.\n");
}

void msg_show_board(void) {
    printf("\n");
    printf("=== Current Board ===\n\n");
}

void msg_after_board(void) {
    printf("\n=====================\n");
}

void msg_board_in_bounds(void) {
    printf("Invalid move: position is outside the board.\n");
}

void msg_board_is_empty(void) {
    printf("Invalid move: this cell is already occupied.\n");
}

void msg_player_wins(char player) {
    printf("\nPlayer %c wins! Congratulations!\n", player);
}

void msg_game_draw(void) {
    printf("\nIt's a draw!\n");
}

void msg_board_size(void){
    printf("-You can choose the size of your board.\n");
    printf("-The size of the board can be between 3 and 7\n\n");
    printf("\nEnter the board size: ");
}

void msg_end(void){
    printf("\n==============================\n");
    printf(" Match finished!\n");
    printf("==============================\n");
    printf("Play again?\n");
    printf("1 - Yes\n");
    printf("0 - Exit\n");
    printf("Your choice: ");
}
