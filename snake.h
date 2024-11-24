
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "queue.h"

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

void increase_length(Queue *snake, SnakePiece piece);
void decrease_length(Queue *snake);

#endif