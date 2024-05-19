#include<stdio.h>
typedef struct queue {
    int items[100];
    int front, rear;
} queue;

void initq(queue *q) {
    q->front = q->rear = -1;
}

int isqmpty(queue *q) {
    return (q->front == -1);
}

void enqueue(queue *q, int value) {
    if (q->rear == 100 - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (isqmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(queue *q) {
    if (isqmpty(q)) {
        printf("Queue Underflow\n");
        return -1; 
    }
    int value = q->items[q->front++];
    if (q->front > q->rear) {
        initq(q);
    }
    return value;
}
