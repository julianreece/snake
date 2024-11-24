
#include "board.h"
#include "game.h"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main() {

    initscr();
    refresh();

    noecho();

    BoardSize boardsize = {
        getmaxy(stdscr),
        getmaxx(stdscr),
        BOARD_ROWS,
        BOARD_COLS
    };

    Game *game = malloc(sizeof(Game));
    Board *board = malloc(sizeof(Board));

    initialize(game, board, &boardsize);

    while (!is_over(game)) {
        process_input(game);

        update_state(game);

        redraw(game);
    }

    wrefresh(board->boardwin);

    getch();
    endwin();

    free(game);
    free(board);

    return 0;
}