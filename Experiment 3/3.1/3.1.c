
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

void initQueue(MyQueue *q) {
    q->top1 = -1;
    q->top2 = -1;
}

void push(MyQueue *q, int x) {
    q->s1[++q->top1] = x;
}

void shiftStacks(MyQueue *q) {
    if (q->top2 == -1) {
        while (q->top1 != -1) {
            q->s2[++q->top2] = q->s1[q->top1--];
        }
    }
}

int pop(MyQueue *q) {
    shiftStacks(q);
    if (q->top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->s2[q->top2--];
}

int peek(MyQueue *q) {
    shiftStacks(q);
    if (q->top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->s2[q->top2];
}

bool empty(MyQueue *q) {
    return q->top1 == -1 && q->top2 == -1;
}

int main() {
    MyQueue q;
    initQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Front element: %d\n", peek(&q));
    printf("Removed element: %d\n", pop(&q));
    printf("Front element: %d\n", peek(&q));
    printf("Is queue empty? %s\n", empty(&q) ? "Yes" : "No");

    return 0;
}
