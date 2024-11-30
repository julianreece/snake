
#include "board.h"
#include "game.h"
#include "fruit.h"

int main() {
    FILE* highscore_file = fopen("highscores.txt", "r");
    if (highscore_file == NULL) {
        printf("ERROR: Could not open file\n");
        return -1;
    }

    int highscore; 
    fscanf(highscore_file, "%d", &highscore);
    freopen("highscores.txt", "w", highscore_file);

    if (highscore_file == NULL) {
        printf("ERROR: Could not reopen file\n");
        return -1;
    }

    printf("Loaded highscore: %d\n", highscore);

    initscr();
    start_color();

    if (!has_colors()) {
        printf("ERROR: Color not supported\n");
        endwin();
        return -1;
    }

    init_pair(1, COLOR_GREEN, COLOR_GREEN); /* snake color */
    init_pair(2, COLOR_RED, COLOR_RED); /* fruit color */

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
        wtimeout(game.board->boardwin, game.delay);

        process_input(&game, &snake);

        update_state(&game, &snake, &fruit, &boardsize);

        redraw(&game);
    }

    mvwprintw(game.board->boardwin, 5, 5, "GAME OVER");
    mvwprintw(game.board->boardwin, 6, 5, "Score: %d", game.score);

    wgetch(game.board->boardwin);
    endwin();

    printf("Score: %d\n", game.score);
    if (game.score > highscore) {
        highscore = game.score;
        fprintf(highscore_file, "%d", highscore);
        printf("NEW HIGH SCORE: %d\n", highscore);
    } else {
        // print old highscore
        fprintf(highscore_file, "%d", highscore);
    }

    fclose(highscore_file);

    free(snake.snake_queue);

    return 0;
}
