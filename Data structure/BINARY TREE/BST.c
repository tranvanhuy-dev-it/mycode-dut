#include<stdio.h>
#include<stdlib.h>

struct NodeInfo{
    struct NodeInfo *l;
    struct NodeInfo *r;
    struct NodeInfo *p;
    int key;
};

typedef struct NodeInfo *BST, *TreeNode;

void preorder(BST T) {
    if (T != NULL) {
        printf("%d ", T->key);
        preorder(T->l);
        preorder(T->r);
    }
}

TreeNode tree_minimum(BST T) {
    while (T->l != NULL) T = T->l;
    return T;
}

TreeNode tree_maximum(BST T) {
    while (T->r != NULL) T = T->r;
    return T;
}

TreeNode tree_search(BST T, int key) {
    if (T == NULL || T->key == key) return T;

    if (T->key > key) return tree_search(T->l, key);
    else return tree_search(T->r, key);
}

TreeNode tree_successer(TreeNode x) {
    if (x->r != NULL) return tree_minimum(x->r);

    TreeNode y = x->p;
    while (y != NULL && x == y->r) {
        x = y;
        y = y->p;
    }
    return y;
}

void tree_insert(BST *T, int key) {
    TreeNode z = (TreeNode)malloc(sizeof(struct NodeInfo));
    z->key = key;
    z->l = NULL;
    z->r = NULL;
    
    TreeNode y = NULL;
    TreeNode x = *T;
    while (x != NULL) {
        y = x;
        if (x->key > key) x = x->l;
        else x = x->r;
    }
    z->p = y;
    if (y == NULL) *T = z;
    else if (z->key < y->key) y->l = z;
    else y->r = z;
}

TreeNode tree_delete(BST *T, TreeNode z) {
    if (z == NULL) return NULL;
    TreeNode x, y;

    if (z->l == NULL || z->r == NULL) 
        y = z;
    else 
        y = tree_successer(z);

    if (y->l != NULL) 
        x = y->l;
    else if (y->r != NULL) 
        x = y->r;
    else
        x = NULL;

    if (x != NULL) 
        x->p = y->p;

    if (y->p == NULL) 
        *T = x;
    else if (y->p->l == y) 
        y->p->l = x;
    else 
        y->p->r = x;

    if (y != z) 
        z->key = y->key;

    free(y);
    return y;
}

int main() {

    
    BST T = NULL;
    tree_insert(&T, 10);
    tree_insert(&T, 5);
    tree_insert(&T, 30);
    tree_insert(&T, 2);
    tree_insert(&T, 25);
    tree_insert(&T, 45);
    tree_insert(&T, 20);
    tree_insert(&T, 22);

    preorder(T); printf("\n");

    tree_delete(&T, tree_search(T, 2));
    preorder(T); printf("\n");



    return 0;
}