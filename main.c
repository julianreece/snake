
#include "board.h"
#include "game.h"
#include "fruit.h"

int main() {

    initscr();
    start_color();

    if (!has_colors()) {
        printf("ERROR: Color not supported\n");
        endwin();
        return -1;
    }

    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_RED);

    refresh();

    noecho();

    curs_set(0);

    BoardSize boardsize = {
        getmaxy(stdscr),
        getmaxx(stdscr),
        20, // height
        50 // width
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
