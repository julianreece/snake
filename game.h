
#ifndef _GAME_H_
#define _GAME_H_

#include <ncurses.h>
#include <stdbool.h>

#include "board.h"

typedef struct {
    Board *board;
    int game_over;
} Game;

void initialize(Game *game, Board *board, BoardSize *boardsize);
void process_input(Game* game);
bool is_over(Game* game);
void update_state(Game *game);
void redraw(Game *game);

#endif