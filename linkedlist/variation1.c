#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *List;

void initList(List *L) {
    *L = NULL;
}

void insertFirst(List *L, int data) {
    List newNode = (List)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = *L;
        *L = newNode;
    }
}

void insertLast(List *L, int data) {
    List newNode = (List)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        if (*L == NULL) {
            *L = newNode;
        } else {
            List temp = *L;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void deleteFirst(List *L) {
    if (*L != NULL) {
        List temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

void deleteLast(List *L) {
    if (*L != NULL) {
        if ((*L)->next == NULL) {
            free(*L);
            *L = NULL;
        } else {
            List temp = *L;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void display(List L) {
    List temp = L;
    printf("[");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(", ");
        temp = temp->next;
    }
    printf("]\n");
}

int main() {
    List L;
    initList(&L);
    
    insertFirst(&L, 10);
    insertFirst(&L, 20);
    insertLast(&L, 5);
    display(L);
    
    deleteFirst(&L);
    display(L);
    
    deleteLast(&L);
    display(L);
    
    return 0;
}
