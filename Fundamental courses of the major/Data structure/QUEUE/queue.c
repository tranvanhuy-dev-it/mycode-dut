#include<stdio.h>
#include<stdlib.h>

struct ElementType{
    int value;
};

struct QueueInfo{
    unsigned int Capacity;
    unsigned int rear;
    unsigned int front;
    unsigned int count;
    struct ElementType *data;
};

typedef struct QueueInfo *Queue;

Queue CreateQueue(int Capacity) {
    Queue Q = (Queue)malloc(sizeof(struct QueueInfo));
    if (Q == NULL) return NULL;
    Q->Capacity = Capacity;
    Q->rear = 0;
    Q->front = 1;
    Q->count = 0;
    Q->data = (struct ElementType*)malloc(Capacity * sizeof(struct ElementType));
    if (Q->data == NULL) return NULL;
    return Q;
}

int isFull(Queue Q) {
    return Q->count == Q->Capacity;
}

int isEmpty(Queue Q) {
    return Q->count == 0;
}

unsigned int increase(unsigned int value, Queue Q) {
    if (++value == Q->Capacity) {
        value = 0;
    }
    return value;
}

void enQueue(Queue Q, struct ElementType data) {
    if (isFull(Q)) {
        printf("The Queue is Full\n");
    }
    Q->rear = increase(Q->rear, Q);
    Q->count++;
    Q->data[Q->rear] = data;
}

struct ElementType* deQueue(Queue Q) {
    if (isEmpty(Q)) {
        printf("The Queue is Empty\n");
        return NULL;
    }
    struct ElementType* temp = &Q->data[Q->front];
    Q->front = increase(Q->front, Q);
    Q->count--;
    return temp;
}

int main() {

    Queue Q = CreateQueue(100);
    struct ElementType e1, e2, e3;
    e1.value = 1;
    e2.value = 2;
    e3.value = 3;

    enQueue(Q, e1);
    enQueue(Q, e2);
    enQueue(Q, e3);

    struct ElementType* e;

    while (!isEmpty(Q)) {
        e = deQueue(Q);
        printf("value = %d\n", e->value);
    }
    return 0;
}