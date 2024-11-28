
#include "board.h"

void clear_win(WINDOW* win) {
    wclear(win);
    add_border(win);
}

void add_border(WINDOW* win) {
    box(win, 0, 0);
}

void add_char_at(WINDOW* win, int y, int x, chtype ch) {
    mvwaddch(win, y, x, ch);
}

chtype get_input(WINDOW* win) {
    return wgetch(win);
}

chtype get_char_at(WINDOW* win, int y, int x) {
    return mvwinch(win, y, x);
}

void add_empty(WINDOW* win, int y, int x) {
    add_char_at(win, y, x, ' ');
}