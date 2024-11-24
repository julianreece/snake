
#ifndef _GAME_H_
#define _GAME_H_

#include <ncurses.h>
#include <stdbool.h>
#include <time.h>

#include "snake.h"
#include "board.h"
// #include "fruit.h"

typedef struct {
    Board *board;
    int game_over;
    // Fruit *fruit;
} Game;

void initialize(Game *game, Board *board, Snake *snake, BoardSize *boardsize);
void process_input(Game* game);
bool is_over(Game* game);
void update_state(Game *game, BoardSize boardsize);
void redraw(Game *game);

// void add_model(Game *game /*Fruit fruit*/);

void get_empty_coordinate(Game *game, int *x, int *y, BoardSize *boardsize);


#endif