#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

EPtr L;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main() {

}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(L->count == MAX){
        printf("List is full\n");
    }
    if(position < 0 || position > L->count){
        printf("Invalid position\n");
    }
    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[position] = data;
    L->count++;
}
