#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    L = initialize(L);
    L = insertPos(L, 5, 0);
    L = insertPos(L, 10, 1);
    L = insertPos(L, 15, 2);
    L = insertPos(L, 20, 3);
    printf("List after insertions:\n");
    display(L);
    L = deletePos(L, 1);
    printf("List after deletion at position 1:\n");
    display(L);
    int pos = locate(L, 15);
    if(pos != -1){
        printf("Element 15 found at position: %d\n", pos);
    } else {
        printf("Element not found\n");
    }
    printf("List after inserting 12:\n");
    L = insertSorted(L, 12);
    display(L);
    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == MAX){
        printf("List is full\n");
        return L;
    }
    if(position < 0 || position > L.count){
        printf("Invalid position\n");
        return L;
    }
    for(int i = L.count; i > position; i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(L.count == 0){
        printf("List is empty\n");
        return L;
    }
    if(position < 0 || position >= L.count){
        printf("Invalid position\n");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;   
}

List insertSorted(List L, int data){
    if(L.count == MAX){
        printf("List is full\n");
        return L;
    }
    int position = 0;
    while(position < L.count && L.elem[position] < data){
        position++;
    }
    return insertPos(L, data, position);
}

void display(List L){
    if(L.count == 0){
        printf("List is empty\n");
        return;
    }
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
