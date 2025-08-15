#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct StackInfo{
    int Capacity;
    int top;
    int *c;
};

typedef struct StackInfo *Stack;

Stack create(int Capacity) {
    Stack S = (Stack)malloc(sizeof(struct StackInfo));
    if (S == NULL) return NULL;
    S->top = -1;
    S->Capacity = Capacity;
    S->c = (int*)malloc(Capacity*sizeof(int));
    return S;
}

int isEmpty(Stack S) {
    return S->top == -1;
}

int isFull(Stack S) {
    return S->top == S->Capacity - 1;
}

void push(Stack S, int c) {
    if (isFull(S)) {
        printf("The stack is Full!\n");
        return;
    }
    S->top++;
    S->c[S->top] = c;
}

int pop(Stack S) {
    if (isEmpty(S)) {
        printf("The stack is Empty!\n");
        return -1;
    }
    S->top--;
    return S->c[S->top + 1];
}

int top(Stack S) {
    if (isEmpty(S)) {
        printf("The stack is Empty!\n");
        return -1;
    }
    return S->c[S->top];
}


int main() {

    Stack S = create(100);
    char s[] = "1 2 3 * + 4 5 * 6 + 7 * + ";
    char *temp = strtok(s, " ");
    while (temp != NULL) {
        if (strcmp(temp, "+") == 0 || strcmp(temp, "-") == 0 || strcmp(temp, "*") == 0 || strcmp(temp, "/") == 0){
            int a, b;
            a = pop(S);
            b = pop(S);
            if (strcmp(temp, "+") == 0) push(S, b + a);
            else if (strcmp(temp, "-") == 0) push(S, b - a);
            else if (strcmp(temp, "*") == 0) push(S, b * a);
            else if (strcmp(temp, "/") == 0) push(S, b / a);
        }
        else push(S, atoi(temp));
        temp = strtok(NULL, " ");
    } 
    int result = pop(S);
    printf("Ket qua: %d\n", result);

    return 0;
}