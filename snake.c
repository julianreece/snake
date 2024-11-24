
#include "snake.h"

void increase_length(Queue *snake, SnakePiece piece) {
    queue_enqueue(snake, piece);
}

void decrease_length(Queue *snake) {
    queue_dequeue(snake);
}