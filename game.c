
#include "game.h"

void initialize(Game *game, Board *board, Snake *snake, Fruit *fruit, BoardSize *boardsize) {
    board->boardwin = newwin(boardsize->rows, boardsize->cols, (boardsize->y_max/2)-(boardsize->rows/2), (boardsize->x_max/2)-(boardsize->cols/2));
    game->board = board;
    game->game_over = false;
    game->score = 0;

    keypad(game->board->boardwin, true);
    add_border(game->board);

    snake->snake_queue = create_queue();
    change_direction(snake, RIGHT);

    SnakePiece head = {
        5, 5, '#'
    };

    add_char_at(board, head.y, head.x, head.icon);
    increase_length(snake, head);

    head = next_head(snake, RIGHT);
    add_char_at(board, head.y, head.x, head.icon);
    increase_length(snake, head);

    head = next_head(snake, RIGHT);
    add_char_at(board, head.y, head.x, head.icon);
    increase_length(snake, head);

    draw_fruit(game, fruit, boardsize);
}

void process_input(Game *game, Snake *snake) {
    chtype input = get_input(game->board);

    switch (input) {
        case KEY_UP:
            change_direction(snake, UP);
            break;
        case KEY_DOWN:
            change_direction(snake, DOWN);
            break;
        case KEY_LEFT:
            change_direction(snake, LEFT);
            break;
        case KEY_RIGHT:
            change_direction(snake, RIGHT);
            break;
        default:
            // any other key pressed
            break;
    }
}

bool is_over(Game* game) {
    return game->game_over;
}

void update_state(Game *game, Snake *snake, Fruit *fruit, BoardSize *boardsize) {  
    SnakePiece next = next_head(snake, snake->curr_dir);

    switch (get_char_at(game->board, next.y, next.x)) {
        case ' ': {
            int empty_row = tail(snake->snake_queue).y;
            int empty_col = tail(snake->snake_queue).x;
            add_empty(game->board, empty_row, empty_col);
            decrease_length(snake);
            break;
        }
        case '@': {
            game->score++;

            draw_fruit(game, fruit, boardsize);
            
            break;
        }
        default:
            game->game_over = true;
            break;
    }

    add_char_at(game->board, next.y, next.x, '#');
    increase_length(snake, next);
}

void redraw(Game* game) {
    wrefresh(game->board->boardwin);
}

void get_empty_coordinate(Game *game, int *y, int *x, BoardSize *boardsize) {
    srand(time(NULL));
    do {
        *y = rand() % boardsize->rows;
        *x = rand() % boardsize->cols;
    } while (mvwinch(game->board->boardwin, *y, *x) != ' ');
}

void add_fruit(Game *game, Fruit *fruit) {
    add_char_at(game->board, fruit->y, fruit->x, '@');
}

void draw_fruit(Game *game, Fruit *fruit, BoardSize *boardsize) {
    int y, x;
    get_empty_coordinate(game, &y, &x, boardsize);
    fruit->y = y;
    fruit->x = x;

    add_fruit(game, fruit);
}