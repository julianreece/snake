
#ifndef _BOARD_H_
#define _BOARD_H_

#include <ncurses.h>
#include <stdlib.h>

typedef struct {
    WINDOW* boardwin;
} Board;

typedef struct {
    int y_max;
    int x_max;
    int rows;
    int cols;
} BoardSize;

void clear_win(Board* board);
void add_border(Board* board);
void addCharAt(Board* board, int y, int x, chtype ch);
chtype get_input(Board* board);

#endif