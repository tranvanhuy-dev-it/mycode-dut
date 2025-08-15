#include<stdio.h>
#include<stdlib.h>

struct ElementType{
    int key;
    char *name;
};

struct NodeInfo{
    struct ElementType e;
    struct NodeInfo *Next;
};

typedef struct NodeInfo *NODE;

struct HashTableInfo{
    int Capacity;
    NODE *data;
};

typedef struct HashTableInfo *HashTable;

HashTable Create(int Capacity) {
    HashTable H = (HashTable)malloc(sizeof(struct HashTableInfo));
    if (H == NULL) return NULL;

    H->data = (NODE*)malloc(Capacity * sizeof(NODE));
    if (H->data == NULL) return NULL;

    H->Capacity = Capacity;

    for (int i = 0; i < Capacity; i++) {
        H->data[i] = (NODE)malloc(sizeof(struct NodeInfo));
        H->data[i]->Next = NULL;
    }

    return H;
}

int hash_function(int key, HashTable H) {
    return key % H->Capacity;
}

void insert(HashTable H, struct ElementType e) {
    NODE newElement = (NODE)malloc(sizeof(struct NodeInfo));
    newElement->e = e;

    int pos = hash_function(e.key, H);

    newElement->Next = H->data[pos]->Next;
    H->data[pos]->Next = newElement;
}

void show(HashTable H) {
    for (int i = 0; i < H->Capacity; i++) {
        if (H->data[i]->Next != NULL) {
            NODE tmp = H->data[i]->Next;
            printf("%d: ", i);
            while(tmp != NULL) {
                printf("%d ", tmp->e.key);
                tmp = tmp->Next;
            }
            printf("\n");
        }
    }
}
 
NODE search(HashTable H, int key) {
    int pos = hash_function(key, H);
    NODE tmp = H->data[pos]->Next;
    while (tmp != NULL && tmp->e.key != key) {
        tmp = tmp->Next;
    }
    return tmp;
}


int main() {

    HashTable H = Create(9);
    struct ElementType e1, e2, e3, e4, e5, e6, e7, e8, e9;
    e1.key = 5;
    e2.key = 28;
    e3.key = 19;
    e4.key = 15;
    e5.key = 20;
    e6.key = 33;
    e7.key = 17;
    e8.key = 12;
    e9.key = 10;

    insert(H, e1);
    insert(H, e2);
    insert(H, e3);
    insert(H, e4);
    insert(H, e5);
    insert(H, e6);
    insert(H, e7);
    insert(H, e8);
    insert(H, e9);

    show(H);

    NODE n = search(H, 20);
    if (n == NULL) {
        printf("Not found!\n");
    } else {
        printf("%d \n", 28);
    }

    return 0;
}
//khong thi ham delete