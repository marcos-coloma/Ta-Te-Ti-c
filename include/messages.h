#ifndef MESSAGES_H
#define MESSAGES_H

void input_error(void);
void msg_title(void);
void msg_game_menu(void);
void msg_game_start(int size);
void msg_not_implemented(void);
void msg_end(void);
void msg_player_turn(char player);
void msg_get_move(void);
void msg_invalid_board(void);
void msg_show_board(void);
void msg_after_board(void);
void msg_board_in_bounds(void);
void msg_board_is_empty(void);
void msg_player_wins(char player);
void msg_game_draw(void);
void msg_board_size(void);
void msg_choose_player(void);
void msg_cpu_turn(char cpu_player);
void msg_choose_difficulty(void);

#endif