
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "queue.h"

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    Queue *snake_queue;
    Direction curr_dir;
} Snake;

void increase_length(Snake *snake, SnakePiece piece);
void decrease_length(Snake *snake);
void change_direction(Snake *snake, Direction new_direction);
SnakePiece next_head(Snake *snake, Direction direction);
// void add_piece(Snake *snake, SnakePiece piece);

#endif