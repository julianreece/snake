
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

void clear_win(WINDOW* win);
void add_border(WINDOW* win);
void add_char_at(WINDOW* win, int y, int x, chtype ch);
chtype get_input(WINDOW* win);
chtype get_char_at(WINDOW* win, int y, int x);
void add_empty(WINDOW* win, int y, int x);

#endif