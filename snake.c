
#include "snake.h"

void increase_length(Snake *snake, SnakePiece piece) {
    queue_enqueue(snake->snake_queue, piece);
}

void decrease_length(Snake *snake) {
    queue_dequeue(snake->snake_queue);
}

void change_direction(Snake *snake, Direction new_direction) {
    snake->curr_dir = new_direction;
}

SnakePiece next_head(Snake *snake, Direction direction) {
    int row = head(snake->snake_queue).y;
    int col = head(snake->snake_queue).x;

    switch (direction) {
        case UP:
            row--;
            break;
        case DOWN:
            row++;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
            break;
        default:
            exit(1);
            break;
    }

    SnakePiece new_piece = {
        row,
        col,
        '#'
    };
    
    return new_piece;
}

// void add_piece(Snake *snake, SnakePiece piece) {
//     increase_length(snake, piece);
// }