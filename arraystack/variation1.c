#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack S;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main(){
    Stack* s = initialize();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    display(s);
    printf("%d popped from stack\n", pop(s));
    printf("Top element is %d\n", peek(s));
    display(s);
    return 0;
}


Stack* initialize(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s){
    if(s->top == MAX - 1)
        return true;
    return false;
}

bool isEmpty(Stack* s){
    if(s->top == -1)
        return true;
    return false;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->items[i]);
    }
    printf("\n");
}





