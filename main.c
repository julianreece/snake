
#include "board.h"
#include "game.h"
#include "fruit.h"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main() {

    initscr();
    start_color();

    refresh();

    noecho();

    curs_set(0);

    BoardSize boardsize = {
        getmaxy(stdscr),
        getmaxx(stdscr),
        BOARD_ROWS,
        BOARD_COLS
    };
    Game game;
    Board board;
    Snake snake;
    Fruit fruit;

    initialize(&game, &board, &snake, &fruit, &boardsize);

    while (!is_over(&game)) {
        wtimeout(game.board->boardwin, 500);

        process_input(&game, &snake);

        update_state(&game, &snake, &fruit, &boardsize);

        redraw(&game);
    }

    mvwprintw(game.board->boardwin, 5, 5, "GAME OVER");
    mvwprintw(game.board->boardwin, 6, 5, "Score: %d", game.score);

    wgetch(game.board->boardwin);
    endwin();

    free(snake.snake_queue);

    return 0;
}