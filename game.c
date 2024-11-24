
#include "game.h"

void initialize(Game *game, Board *board, Snake *snake, BoardSize *boardsize) {
    board->boardwin = newwin(boardsize->rows, boardsize->cols, (boardsize->y_max/2)-(boardsize->rows / 2), (boardsize->x_max/2)-(boardsize->cols / 2));
    game->board = board;
    
    snake->snake_queue = create_queue();

    add_border(game->board);

    SnakePiece next = {
        1, 1, '#'
    };

    increase_length(snake, next);

    next = next_head(snake, UP);

    increase_length(snake, next);

}

void process_input(Game* game) {
    chtype input = get_input(game->board);
}

bool is_over(Game* game) {
    return game->game_over;
}

void update_state(Game *game, BoardSize boardsize) {
    int y, x;
    get_empty_coordinate(game, &y, &x, &boardsize);

    // Fruit fruit = {
    //     y,
    //     x,
    //     '@'
    // };

    // add_model(game, fruit);
}

void redraw(Game* game) {
    wrefresh(game->board->boardwin);
}

// void add_model(Game *game, Fruit model) {
//     add_char_at(game->board, model.y, model.x, model.icon);
// }

void get_empty_coordinate(Game *game, int *y, int *x, BoardSize *boardsize) {
    srand(time(NULL));
    do {
        *y = rand() % boardsize->rows;
        *x = rand() % boardsize->cols;
    } while (mvwinch(game->board->boardwin, *y, *x) != ' ');
}