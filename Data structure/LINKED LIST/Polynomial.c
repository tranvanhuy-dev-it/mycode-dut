#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
    int coeff;  //he so
    int exp;    //mu
    struct Node*Next;
};

typedef struct Node *Polynomial;
typedef struct Node *Position;

Polynomial create() {
    Position headnode = (Polynomial)malloc(sizeof(struct Node));
    headnode->exp = INT_MAX;
    headnode->Next = NULL;
    return headnode;
}

void insert(Polynomial poly, int coeff, int exp) {
    Position p = poly;
    while (p->Next != NULL && p->Next->exp >= exp){
        p = p->Next;
    }
    if (p->exp == exp){
        p->coeff += coeff;
    }
    else {
        Position newNode = (Position)malloc(sizeof(struct Node));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->Next = p->Next;
        p->Next = newNode;
    }
}

void show (Polynomial poly) {
    poly = poly->Next;
    while (poly != NULL) {
        if (poly->coeff != 0) {
            printf("%dx^%d  ", poly->coeff, poly->exp);
        }
        poly = poly->Next;
    }
}

Polynomial add(Polynomial A, Polynomial B) {
    A = A->Next;
    B = B->Next;
    Polynomial C = create();
    while(A != NULL) {
        insert(C, A->coeff, A->exp);
        A = A->Next;
    }
    while(B != NULL) {
        insert(C, B->coeff, B->exp);
        B = B->Next;
    }
    return C;
}

Polynomial mult(Polynomial A, Polynomial B){
    Polynomial C = create();
    A = A->Next;
    B = B->Next;
    while (A != NULL) {
        Polynomial temp = B;
        while (B != NULL) {
            insert(C, A->coeff * B->coeff, A->exp + B->exp);
            B = B->Next;
        }
        B = temp;
        A = A->Next;
    }
    return C;
}

int main() {
    Polynomial A, B, C;

    A = create();
    B = create();

    insert(A, -1, 5);
    insert(A, 3, 1);
    insert(A, 1, 0);
    insert(B, 1, 2);
    insert(B, -2, 0);

    printf("A = ");
    show(A);

    printf("\nB = ");
    show(B);

    C = add(A, B);
    printf("\nA + B = ");
    show(C);

    C = mult(A, B);
    printf("\nA * B = ");
    show(C);

    printf("\n");

}