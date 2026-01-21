#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct StackInfo{
    int Capacity;
    int top;
    char *c;
};

typedef struct StackInfo *Stack;

Stack CreateStack(int Capacity) {
    Stack S = (Stack)malloc(sizeof(struct StackInfo));
    if (S == NULL) return NULL;
    S->Capacity = Capacity;
    S->top = -1;
    S->c = (char*)malloc(sizeof(char)*Capacity);
    return S;
}

int isFull(Stack S) {
    return S->top == S->Capacity - 1;
} 

int isEmpty(Stack S) {
    return S->top == -1;
}

void push(Stack S, char c) {
    if (isFull(S)) {
        printf("stack is full!\n");
        return;
    }
    S->top++;
    S->c[S->top] = c;
}

int pop(Stack  S) {
    if (isEmpty(S)) {
        puts("Stack is empty!\n");
        return -1;
    }
    S->top--;
    return S->c[S->top + 1];
}

int top(Stack  S) {
    if (isEmpty(S)) {
        puts("Stack is empty!\n");
        return -1;
    }
    return S->c[S->top];
}

int main() {

    Stack S = CreateStack(100);
    char s[] = "1+2*3+(4*5+6)*7";
    char kq[100];
    char pri[256];
    pri['*'] = 2;
    pri['/'] = 2;
    pri['+'] = 1;
    pri['-'] = 1;
    pri['('] = 0;
    pri[')'] = 0;
    int l = strlen(s);
    int p = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '(') push(S, s[i]);
        else if (s[i] == ')') {
            while (!isEmpty(S) && top(S) != '('){
                kq[p++] = pop(S);
            }
            if (!isEmpty(S)) pop(S);
        }
        else if (isdigit(s[i])) {
            kq[p++] = s[i];
        }
        else {
            while (!isEmpty(S) && top(S) != '(' && pri[top(S)] >= pri[s[i]]) {
                kq[p++] = pop(S);
            }
            push(S, s[i]);
        }
    }
    while (!isEmpty(S)) {
        kq[p++] = pop(S);
    }
    kq[p] = '\0';
    int size = strlen(kq);
    for (int i = 0; i < size; i++) {
        printf("%c ", kq[i]);
    }
    printf("\n");
    return 0;
}