
#include "queue.h"

Node *create_node(SnakePiece data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        // memory was not allocated properly
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}   

Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));

    queue->front = queue->back = NULL;
    return queue;
}

int is_empty(Queue *queue) {
    return queue->front == NULL;
}

void queue_enqueue(Queue *queue, SnakePiece data) {
    Node *node = create_node(data);
    if (!node) {
        exit(1);
    }

    // if queue is empty
    if (queue->back == NULL) {
        queue->front = queue->back = node;
        return;
    }

    queue->back->next = node;
    queue->back = node;
}   

SnakePiece queue_dequeue(Queue *queue) {
    if (is_empty(queue)) {
        // queue underflow
        SnakePiece null = {
            -1, -1, -1
        };
        return null;
    }
    SnakePiece head_data = queue->front->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->back = NULL;
    }

    SnakePiece data = head_data;
    return data;
}

SnakePiece peek(Queue *queue) {
    if (is_empty(queue)) {
        SnakePiece null = {
            -1, -1, -1
        };
        return null;
    }

    return queue->front->data;
}