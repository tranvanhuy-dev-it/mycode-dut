#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

struct ElementType {
    char *name;
    int id;
};

struct Node {
    struct Node *Next;
    struct ElementType e;
};

typedef struct Node *List;
typedef struct Node *Position;

int Insert(List *pL, struct ElementType e, Position p) {
    Position newNode = (List)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return false;
    }
    newNode->e = e;

    if (*pL == NULL || p == NULL) {
        newNode->Next = *pL;
        *pL = newNode;
    }
    else{
        newNode->Next = p->Next;
        p->Next = newNode;
    }
    return true;
    
}

void show(List pL) {
    while (pL != NULL) {
        printf("ID: %d        Name: %s\n", pL->e.id, pL->e.name);
    }
    pL = pL->Next;
}

Position findID(List pL, int id){
    while(pL != NULL && pL->e.id == id) {
        pL = pL->Next;
    }
    return pL;
}

int main() {

    List stdList = NULL;

    struct ElementType e1, e2, e3, e4;
    e1.id = 1; e1.name = "Nguyen Van A";
    e2.id = 2; e2.name = "Nguyen Van B";
    e3.id = 3; e3.name = "Nguyen Van C";
    e4.id = 4; e4.name = "NGUYEN VAN D";

    Insert(&stdList, e1, NULL);
    Insert(&stdList, e2, stdList);
    Insert(&stdList, e2, stdList->Next);

    show(stdList);

    
    return 0;
}