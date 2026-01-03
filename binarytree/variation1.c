#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *Tree;

Tree createNode(int data) {
    Tree newNode = (Tree)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insert(Tree *T, int data) {
    if (*T == NULL) {
        *T = createNode(data);
    } else {
        if (data < (*T)->data) {
            insert(&(*T)->left, data);
        } else {
            insert(&(*T)->right, data);
        }
    }
}

void inorder(Tree T) {
    if (T != NULL) {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

void preorder(Tree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(Tree T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}

int main() {
    Tree T = NULL;
    
    insert(&T, 50);
    insert(&T, 30);
    insert(&T, 70);
    insert(&T, 20);
    insert(&T, 40);
    insert(&T, 60);
    insert(&T, 80);
    
    printf("Inorder: ");
    inorder(T);
    printf("\n");
    
    printf("Preorder: ");
    preorder(T);
    printf("\n");
    
    printf("Postorder: ");
    postorder(T);
    printf("\n");
    
    return 0;
}
