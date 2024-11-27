
#ifndef _GAME_H_
#define _GAME_H_

#include <ncurses.h>
#include <stdbool.h>
#include <time.h>

#include "snake.h"
#include "board.h"
#include "fruit.h"

typedef struct {
    Board *board;
    int game_over;
    int score;
} Game;

void initialize(Game *game, Board *board, Snake **snake, Fruit **fruit, BoardSize *boardsize);
void process_input(Game* game, Snake **snake);
bool is_over(Game* game);
void update_state(Game *game, Snake **snake, Fruit **fruit, BoardSize boardsize);
void redraw(Game *game);

void get_empty_coordinate(Game *game, int *x, int *y, BoardSize *boardsize);
void add_fruit(Game *game, Fruit **fruit);


#endif