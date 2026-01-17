#ifndef GAME_H
#define GAME_H
typedef enum {
    GAME_PVP  = 0,
    GAME_PVC  = 1,
    GAME_EXIT = 2
} GameMode;

typedef enum {
    AI_EASY = 0,
    AI_NORMAL,
    AI_HARD
} AIDifficulty;

void game_run(void);

#endif