#ifndef GAME_H
#define GAME_H
typedef enum {
    GAME_PVP  = 0,
    GAME_PVC  = 1,
    GAME_EXIT = 2
} GameMode;

void game_run(void);

#endif