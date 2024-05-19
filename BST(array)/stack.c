#include<stdio.h>
typedef struct stack {
    int items[100];
    int top;
} stack;

void inits(stack *s) {
    s->top = -1;
}

int issmpty(stack *s) {
    return (s->top == -1);
}

void push(stack *s, int value) {
    if (s->top == 100 - 1) {
        printf("Stack Overflow\n"); 
        return;
    }
    s->items[++s->top] = value;
}

int pop(stack *s) {
    if (issmpty(s)) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->items[s->top--];
}
