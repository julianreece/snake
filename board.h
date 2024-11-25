
#ifndef _BOARD_H_
#define _BOARD_H_

#include <ncurses.h>
#include <stdlib.h>

#include "queue.h"

typedef struct {
    int y_max;
    int x_max;
    int rows;
    int cols;
} BoardSize;

typedef struct {
    WINDOW* boardwin;
} Board;

void clear_win(Board* board);
void add_border(Board* board);
void add_char_at(Board* board, int y, int x, chtype ch);
chtype get_input(Board* board);
chtype get_char_at(Board* board, int y, int x);

#endif