
#include "game.h"

void initialize(Game *game, Board *board, Snake **snake, BoardSize *boardsize) {
    board->boardwin = newwin(boardsize->rows, boardsize->cols, (boardsize->y_max/2)-(boardsize->rows/2), (boardsize->x_max/2)-(boardsize->cols/2));
    game->board = board;
    game->game_over = false;
    game->score = 0;

    keypad(game->board->boardwin, true);
    add_border(game->board);

    (*snake)->snake_queue = create_queue();
    change_direction((*snake), RIGHT);

    SnakePiece head = {
        5, 5, '#'
    };
    add_char_at(board, head.y, head.x, head.icon);
    increase_length((*snake), head);

    head = next_head((*snake), RIGHT);
    add_char_at(board, head.y, head.x, head.icon);
    increase_length((*snake), head);
}

void process_input(Game *game, Snake **snake) {
    chtype input = get_input(game->board);

    switch (input) {
        case KEY_UP:
            change_direction((*snake), UP);
            break;
        case KEY_DOWN:
            change_direction((*snake), DOWN);
            break;
        case KEY_LEFT:
            change_direction((*snake), LEFT);
            break;
        case KEY_RIGHT:
            change_direction((*snake), RIGHT);
            break;
        default:
            // any other key pressed
            break;
    }
}

bool is_over(Game* game) {
    return game->game_over;
}

void update_state(Game *game, Snake **snake, BoardSize boardsize) {
    // int y, x;   
    // get_empty_coordinate(game, &y, &x, &boardsize);    

    // SnakePiece next = next_head((*snake), (*snake)->curr_dir);

    // int empty_row = (*snake)->snake_queue->back->data.y;
    // int empty_col = (*snake)->snake_queue->back->data.x;
    // add_char_at(game->board, empty_row, empty_col, ' ');
    // decrease_length((*snake));

    // switch (get_char_at(game->board, next.y, next.x)) {
    //     case ' ': // blank space
    //         add_char_at(game->board, next.y, next.x, next.icon);
    //         // mvwprintw(game->board->boardwin, 1, 1, "head x,y: %d,%d", next.x, next.y);
    //         increase_length((*snake), next);

    //         break;
    //     case '@': // fruit
    //         game->score++;
    //         break;
    //     default: // wall or snake
    //         mvwprintw(game->board->boardwin, boardsize.rows / 2, boardsize.cols / 2, "GAME OVER");
    //         game->game_over = true;
    //         break;
    // }

    SnakePiece next = next_head((*snake), (*snake)->curr_dir);

    int empty_row = tail((*snake)->snake_queue).y;
    int empty_col = tail((*snake)->snake_queue).x;
    add_empty(game->board, empty_row, empty_col);
    decrease_length((*snake));

    add_char_at(game->board, next.y, next.x, '#');
    increase_length((*snake), next);
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