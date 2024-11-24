
#include "board.h"

void clear_win(Board* board) {
    wclear(board->boardwin);
    add_border(board);
}

void add_border(Board* board) {
    box(board->boardwin, 0, 0);
}

void addCharAt(Board* board, int y, int x, chtype ch) {
    mvwaddch(board->boardwin, y, x, ch);
}

chtype get_input(Board* board) {
    return wgetch(board->boardwin);
}