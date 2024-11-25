
#include "board.h"
#include "game.h"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main() {

    initscr();
    refresh();

    noecho();

    curs_set(0);

    BoardSize boardsize = {
        getmaxy(stdscr),
        getmaxx(stdscr),
        BOARD_ROWS,
        BOARD_COLS
    };

    Game *game = malloc(sizeof(Game));
    Board *board = malloc(sizeof(Board));
    Snake *snake = malloc(sizeof(Snake));

    initialize(game, board, &snake, &boardsize);

    while (!is_over(game)) {
        wtimeout(game->board->boardwin, 500);

        process_input(game, &snake);

        update_state(game, &snake, boardsize);

        redraw(game);
    }

    getch();
    endwin();

    free(game);
    free(board);
    
    Node *temp = snake->snake_queue->front;
    while (temp != NULL) {
        printf("{%d %d %c} -> ", temp->data.x, temp->data.y, temp->data.icon);
        temp = temp->next;
    }
    printf("NULL\n");
    free(snake->snake_queue);
    free(snake);

    // Queue *snake_queue = create_queue();
    // Snake *snake = malloc(sizeof(Snake));

    // snake->snake_queue = snake_queue;

    // SnakePiece piece1 = {
    //     1, 1, '#'
    // };
    // SnakePiece piece2 = {
    //     1, 1, '@'
    // };
    // SnakePiece piece3 = {
    //     1, 2, '%'
    // };
    // SnakePiece piece4 = {
    //     1, 2, '$'
    // };


    // increase_length(snake, piece1);
    // increase_length(snake, piece2);
    // increase_length(snake, piece3);
    // increase_length(snake, piece4);

    // // Node *temp = snake->snake_queue->front;
    // // while (temp != NULL) {
    // //     printf("{%d %d %c}\n", temp->data.x, temp->data.y, temp->data.icon);
    // //     temp = temp->next;
    // // }

    // printf("%d\n", peek(snake->snake_queue));

    // free(snake);
    // free(snake_queue);

    return 0;
}