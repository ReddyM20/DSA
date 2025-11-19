#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * LC;
    struct node * RC;
}Node, *BST;

void insert(BST *B, int value){
    BST *trav = B;
    while(*trav != NULL && (*trav) -> data != value){
        trav = (*trav) -> data > value ? &(*trav) -> LC : &(*trav) -> RC;
    }
    if(*trav == NULL){
        *trav = (BST) calloc (1, sizeof(Node));
        (*trav) -> data = value;
    }
}

void inorder(BST B){
    if(B != NULL){
    inorder(B -> LC);
    printf("%d", B -> data);
    inorder(B -> RC);
    }
}

int main(){
    BST B = NULL;
    insert(&B, 2);
    insert(&B, 7);
    insert(&B, 6);
    insert(&B, 1);

    inorder(B);
}