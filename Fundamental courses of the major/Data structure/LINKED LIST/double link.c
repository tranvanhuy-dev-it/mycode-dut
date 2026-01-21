#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

typedef struct ElementType{
    int id;
    char *name;
}ElementType;

typedef struct Node{
    struct Node *Next;
    struct Node *Prev;
    ElementType e;
}Node;

typedef Node *List;
typedef Node *Position;

List Create() {
    Position headNode = (Position)malloc(sizeof(Node));
    if (headNode == NULL) {
        return NULL;
    }
    headNode->Next = NULL;
    headNode->Prev = NULL;
    return headNode; 
}

int Insert(List pL, ElementType e, Position p) {
    if (p == NULL) {
        p = pL;
    }
    Position newNode = (Position)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }
    newNode->e = e;
    newNode->Next = p->Next;
    newNode->Prev = p;
    p->Next = newNode;
    if (newNode->Next != NULL) {
        newNode->Next->Prev = newNode;
    }
    return true;
}

void show(List pL) {
    pL = pL->Next;
    while (pL != NULL) {
        printf("ID: %d        Name: %s\n", pL->e.id, pL->e.name);
        pL = pL->Next;
    }
}

void del(Position p){
    if (p == NULL) {
        return;
    }
    p->Prev->Next = p->Next;
    if(p->Next != NULL) {
        p->Next->Prev = p->Next;
    }
}

Position find(List pL, int id) {
    pL = pL->Next;
    while(pL != NULL && pL->e.id == id) {
        pL = pL->Next;
    }
    return pL;
}

int main() {

    List StdList = Create();

    ElementType e1, e2, e3, e4;
    e1.id = 1; e1.name = "Nguyen Van A";
    e2.id = 2; e2.name = "Nguyne Van B";
    e3.id = 3; e3.name = "Nguyen Van C";
    e4.id = 4; e4.name = "Nguyen Van D";

    Insert(StdList, e1, NULL);
    Insert(StdList, e2, NULL);
    Insert(StdList, e3, NULL);

    printf("The List is:\n");
    show(StdList);

    Position p = find(StdList, 2);

    Insert(StdList, e4, p);

    printf("The List is:\n");
    show(StdList);

	p = find(StdList, 1);
    del(p);
    
    printf("The List is:\n");
    show(StdList);

    return 0;
}