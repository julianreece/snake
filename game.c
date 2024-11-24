
#include "game.h"

void initialize(Game *game, Board *board, BoardSize *boardsize) {
    board->boardwin = newwin(boardsize->rows, boardsize->cols, (boardsize->y_max/2)-(boardsize->rows / 2), (boardsize->x_max/2)-(boardsize->cols / 2));
    game->board = board;

    add_border(game->board);
}

void process_input(Game* game) {
    chtype input = get_input(game->board);
}

bool is_over(Game* game) {
    return game->game_over;
}

void update_state(Game *game) {
    //
}

void redraw(Game* game) {
    wrefresh(game->board->boardwin);
}