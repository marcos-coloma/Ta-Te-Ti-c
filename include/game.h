#ifndef GAME_H
#define GAME_H

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)  // usleep toma microsegundos
#endif

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