
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include <ncurses.h>

typedef struct {
    int y;
    int x;
    chtype icon;
} SnakePiece;

typedef struct Node {
    SnakePiece data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* back;
} Queue;

Node *create_node(SnakePiece data);
Queue *create_queue();
int is_empty(Queue *queue);
void queue_enqueue(Queue *queue, SnakePiece data);
SnakePiece queue_dequeue(Queue *queue);
SnakePiece peek(Queue *queue);
SnakePiece tail(Queue *snake);
SnakePiece head(Queue *snake);

#endif