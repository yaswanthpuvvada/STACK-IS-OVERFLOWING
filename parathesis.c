#include <stdio.h>
#include <stdlib.h>

struct node {
    char arr;
    struct node* top;
};

typedef struct node* stack;

int isempty(stack st) {
    if (st == NULL) {
        return 1;
    }
    return 0; // You should also return 0 for a non-empty stack.
}

stack push(stack k, char ar) {
    stack new = (stack)malloc(sizeof(struct node));
    new->top = k;
    new->arr = ar;
    return new;
}

stack pop(stack k) {
    if (isempty(k)) {
        printf("stack underflow\n");
        exit(1);
    }
    stack temp = k;
    k = temp->top;
    free(temp);
    return k;
}

void checkbalance(stack k, char arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == '{') {
            k = push(k, arr[i]);
        }
        if (arr[i] == '}') {
            if (isempty(k)) {
                printf("imbalanced  expression\n");
                exit(1);
            }
            k = pop(k);
        }
        i++;
    }

    if (isempty(k)) {
        printf("balanced expression\n");
    } else {
        printf("imbalanced expression\n");
    }
}

int main() {
    char ar[] = {'a', 'b', 'd', '}', 'x', 'y', '\0'};
    stack s = NULL; // Initialize the stack to NULL
    checkbalance(s, ar);
    return 0; // Add a return statement for successful execution
}
