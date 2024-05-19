
#include "queue.c"
#include "stack.c"
#include"header.h"
void init(bt *tree) {
    tree->size = 100;
    for (int i = 0; i < 100; ++i) {
        tree->tree[i] = -1;
    }
}

void insert(bt *tree, int value) {
    if (tree->tree[0] == -1) {
        tree->tree[0] = value;
        return;
    }

    int i = 0;
    while (i < tree->size) {
        if (value < tree->tree[i]) {
            if (2 * i + 1 < tree->size && tree->tree[2 * i + 1] == -1) {
                tree->tree[2 * i + 1] = value;
                return;
            }
            i = 2 * i + 1;
        } else {
            if (2 * i + 2 < tree->size && tree->tree[2 * i + 2] == -1) {
                tree->tree[2 * i + 2] = value;
                return;
            }
            i = 2 * i + 2;
        }
    }
}

void preorder(bt *tree) {
    stack s;
    inits(&s);
    int index = 0;

    while (index < tree->size && (tree->tree[index] != -1  || !issmpty(&s))) {
        while (index < tree->size && tree->tree[index] != -1) {
            printf("%d ", tree->tree[index]);

            if (2 * index + 2 < tree->size && tree->tree[2 * index + 2] != -1) {
                push(&s, 2 * index + 2);
            }

            if (tree->tree[index] != -1) {
                index = 2 * index + 1;
            }
        }

        if (!issmpty(&s)) {
            index = pop(&s);
        }
    }
}

void inorder(bt *tree) {
    stack s;
    inits(&s);
    int index = 0;

    while (index < tree->size && (tree->tree[index] != -1  || !issmpty(&s))) {
        while (index < tree->size && tree->tree[index] != -1) {
            push(&s, index);
            index = 2 * index + 1;
        }

        if (!issmpty(&s)) {
            index = pop(&s);
            printf("%d ", tree->tree[index]);
            index = 2 * index + 2;
        }
    }
}

void postorder(bt *tree) {
    stack s1, s2;
    inits(&s1);
    inits(&s2);
    int index = 0;

    push(&s1, index);

    while (!issmpty(&s1)) {
        index = pop(&s1);
        push(&s2, index);

        if (tree->tree[index] != -1) {
            if (2 * index + 1 < tree->size && tree->tree[2 * index + 1] != -1) {
                push(&s1, 2 * index + 1);
            }
            if (2 * index + 2 < tree->size && tree->tree[2 * index + 2] != -1) {
                push(&s1, 2 * index + 2);
            }
        }
    }

    while (!issmpty(&s2)) {
        index = pop(&s2);
        printf("%d ", tree->tree[index]);
    }
}

void levelwise(bt *tree) {
    if (tree->tree[0] == -1) {
        printf("Binary Tree is empty.\n");
        return;
    }

    queue q;
    initq(&q);
    enqueue(&q, 0);

    while (!isqmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", tree->tree[current]);

        if (2 * current + 1 < tree->size && tree->tree[2 * current + 1] != -1) {
            enqueue(&q, 2 * current + 1);
        }
        if (2 * current + 2 < tree->size && tree->tree[2 * current + 2] != -1) {
            enqueue(&q, 2 * current + 2);
        }
    }
}

int iscomplete(bt *tree) {
    if (tree->tree[0] == -1) {
        return 0; // Not complete if the tree is empty
    }

    queue q;
    initq(&q);
    enqueue(&q, 0);

    while (!isqmpty(&q)) {
        int current = dequeue(&q);

        if (tree->tree[current] != -1) {
            if (2 * current + 1 < tree->size) {
                enqueue(&q, 2 * current + 1);
            }

            if (2 * current + 2 < tree->size) {
                enqueue(&q, 2 * current + 2);
            }
        } else {
            while (!isqmpty(&q)) {
                int next = dequeue(&q);
                if (tree->tree[next] != -1) {
                    return 0;
                }
            }
        }
    }

    return 1;
}
