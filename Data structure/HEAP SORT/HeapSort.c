#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct HeapInfo{
    unsigned int Capacity;
    unsigned int Heap_Size;
    int *data;
};

typedef struct HeapInfo *Heap;

Heap Create(int Capacity, int data[]) {
    Heap H = (Heap)malloc(sizeof(struct HeapInfo));
    if (H == NULL) return NULL;

    H->Capacity = Capacity;
    H->Heap_Size = Capacity;
    
    H->data = (int*)malloc((Capacity + 1) * sizeof(int));
    if (H == NULL) return NULL;
    for (int i = 1; i <= Capacity; i++) {
        H->data[i] = data[i];
    }
    return H;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void max_heapify(Heap H, unsigned int i) {
    unsigned int l = 2*i;
    unsigned int r = 2*i + 1;
    unsigned int largest = i;
    if (l <= H->Heap_Size && H->data[l] > H->data[largest]) largest = l;
    if (r <= H->Heap_Size && H->data[r] > H->data[largest]) largest = r;
    if (largest != i) {
        swap(&H->data[i], &H->data[largest]);
        max_heapify(H, largest);
    }
    
}

void Build_Heap(Heap H) {
    H->Heap_Size = H->Capacity;
    for (int i = H->Capacity/2; i >= 1; i--) {
        max_heapify(H, i);
    }   
}

void HeapSort(Heap H) {
    Build_Heap(H);
    for (int i = H->Capacity; i > 1; i--) {
        swap(&H->data[i], &H->data[1]);
        H->Heap_Size--;
        max_heapify(H, 1);
    }
}

int heap_maximum(Heap H) {
    return H->data[1];
}

int heap_extract_max(Heap H) {
    if (H->Heap_Size < 1) {
        printf("Heap underflow\n");
        return -1;
    }
    int max = H->data[1];
    H->data[1] = H->data[H->Heap_Size];
    H->Heap_Size--;
    H->Capacity--;
    max_heapify(H, 1);
    return max;
}

void heap_increase_key(Heap H, int i, int key) {
    if (key < H->data[i]) {
        printf("The new key is smaller than the current key\n");
        return;
    }
    H->data[i] = key;
    while(i > 1 && H->data[i] > H->data[i/2]) {
        swap(&H->data[i], &H->data[i/2]);
        i = i/2;
    }
}

void heap_insert_key(Heap H, int key) {
    H->Heap_Size++;
    H->Capacity++;
    realloc(H->data, (H->Capacity + 1) * sizeof(int));
    H->data[H->Heap_Size] = INT_MIN;
    heap_increase_key(H, H->Heap_Size, key);
}

void show(Heap H) {
    for (int i = 1; i <= H->Capacity; i++) {
        printf("%d ", H->data[i]);
    }
    printf("\n");
}


int main() {

    int data[] = {0, 23, 18, 12, 14, 9, 7, 10, 6, 5, 8};
    Heap H = Create(10, data);

    Build_Heap(H);

    heap_insert_key(H, 20);
    heap_insert_key(H, 5);
    heap_insert_key(H, 30);
    heap_insert_key(H, 3);
    heap_insert_key(H, 54);
    heap_insert_key(H, 32);
    heap_insert_key(H, 7);
    show(H);


    return 0;
}