#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List initialize(List L);
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List myList;
    myList = initialize(myList);
    insertLast(&myList, 10);
    insertLast(&myList, 20);
    insertFirst(&myList, 5);
    insertPos(&myList, 15, 2);
    display(&myList);
    printf("Element at index 2: %d\n", retrieve(&myList, 2));
    printf("Index of element 20: %d\n", locate(&myList, 20));
    deletePos(&myList, 1);
    display(&myList);
    deleteStart(&myList);
    display(&myList);
    deleteLast(&myList);
    display(&myList);
    empty(&myList);
    display(&myList);
    return 0;
}

List initialize(List L){
    L.head = NULL;
    L.count = 0;
    return L;
}


void empty(List *list){
    Node *current = list->head;
    Node *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index){
    if(index < 0 || index > list->count){
        printf("Invalid position\n");
        return;
    }
    if(index == 0){
        insertFirst(list, data);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid position\n");
        return;
    }
    if(index == 0){
        deleteStart(list);
        return;
    }
    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid position\n");
        return -1;
    }
    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data){
    Node *current = list->head;
    int index = 0;
    while(current != NULL){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


