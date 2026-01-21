#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define EMPTY -1

struct ElementType {
	char c;
};

struct StackInfo {
	unsigned int capacity;
	int top;
	struct ElementType *stack_array;
};

typedef struct StackInfo *Stack;

Stack createStack(unsigned int capacity) {
	Stack S = (Stack)malloc(sizeof(struct StackInfo));
	if (S == NULL)
		return NULL;
	S->top = -1;
	S->capacity = capacity;
	S->stack_array = (struct ElementType*)malloc(sizeof(struct ElementType) * capacity);
	if (S->stack_array ==NULL)
		return NULL;
	return S;
}

int isEmpty(Stack S) {
	return S->top == EMPTY;
}

int isFull(Stack S) {
	return S->top == S->capacity - 1;
}

void push(Stack S, struct ElementType e) {
	if (isFull(S)) {
		printf("The stack is full already!\n");
		return;
	}
	S->top++;
	S->stack_array[S->top] = e;
}

struct ElementType* pop(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");
		return NULL;
	}
	S->top--;
	return &S->stack_array[S->top + 1];
}

struct ElementType* top(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");
		return NULL;
	}	
	return &S->stack_array[S->top];
}

int main() {
	Stack S = createStack(100);
	
	struct ElementType *e, e1;
	
	char s[] = "(i+5*[(17-j/(6*k))])";
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if( s[i] == '(' || s[i] == '['){			
			e1.c = s[i];
			push(S, e1);
		}
		else if( s[i] == ')' || s[i] == ']' ){
			if (isEmpty(S)) {
				printf("Unbalanced!\n");
				return 0;
			}			
			
			if(s[i] == ')' && top(S)->c == '(' || s[i] == ']' && top(S)->c == '[' ){
				pop(S);				
			} else {
				printf("Unbalanced\n");
				return 0;
			}			
		}
	}
	if (isEmpty(S)) 		
		printf("Balanced\n");
	else
		printf("Unbalanced\n");
	return 0;
}
