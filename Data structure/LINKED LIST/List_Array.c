#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define false 0
#define true 1

typedef struct ElementType{
    unsigned long ID;
    char *name;
} ElementType;

struct ListInfo{
    ElementType *TheArray;
    unsigned long count;
    unsigned long capacity;
};

typedef struct ListInfo *List;
typedef int Position;

List createList(unsigned long capacity){
    List newList = (List)malloc(sizeof(struct ListInfo));
    newList->TheArray = (ElementType*)malloc(capacity*sizeof(struct ElementType));
    if (newList->TheArray == NULL){
        return NULL;
    }
    newList->count = 0;
    newList->capacity = capacity;
    return newList;
}

int insert(List L, struct ElementType e, Position p){
    if (p > L->count || L->count == L->capacity){
        return false;
    }

    Position current = L->count;
    while (current != p) {
        L->TheArray[current] = L->TheArray[current -1];
        current--;
    }
    L->TheArray[p] = e;
    L->count++;
    return true;
}

void del(List L, Position p){
    if (p >= L->count){
        return;
    }
    while(p < L->count-1) {
        L->TheArray[p] = L->TheArray[p+1];
        p++;
    }
    L->count--;
}

void show(List L){
    unsigned long i;
    for (i = 0; i < L->count; i++) {
        printf("ID: %lu              Name: %s\n", L->TheArray[i].ID, L->TheArray[i].name);
    }
}
int main(){
    List listStudent = createList(100);

    struct ElementType e1, e2, e3;
    e1.ID = 1; e1.name = "Nguyen Van A";
    e2.ID = 2; e2.name = "Nguyen Van B";
    e3.ID = 3; e3.name = "Nguyen Van C";

    insert(listStudent, e1, 0);
    insert(listStudent, e2, 1);
    insert(listStudent, e3, 2);

    printf("The list is:\n");
    show(listStudent);

    del(listStudent, 0);
    printf("The list after delete is:\n");
    show(listStudent);

    return 0;
}