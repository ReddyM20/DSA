#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *initialize()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack *s)
{
    return false;
}

bool isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;

    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop from empty stack.\n");
        return -1;
    }

    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);

    return value;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }

    return s->top->data;
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (top to bottom): ");

    Node *temp = s->top;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->next != NULL)
        {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("-> NULL\n");
}

int main()
{
    Stack *S = initialize();

    printf("Stack Operations Demo\n\n");

    printf("Is stack empty? %s\n\n", isEmpty(S) ? "Yes" : "No");

    printf("Pushing elements\n");
    push(S, 1);
    push(S, 3);
    push(S, 5);
    display(S);
    printf("\n");

    printf("Pushing 4\n");
    push(S, 4);
    display(S);
    printf("\n");

    printf("Peek operation\n");
    int topValue = peek(S);
    if (topValue != -1)
    {
        printf("Top element: %d\n", topValue);
    }
    display(S);
    printf("\n");

    printf("Pop operation\n");
    int poppedValue = pop(S);
    if (poppedValue != -1)
    {
        printf("Popped value: %d\n", poppedValue);
    }
    display(S);
    printf("\n");

    printf("Is stack full? %s\n\n", isFull(S) ? "Yes" : "No");

    printf("Popping all elements\n");
    while (!isEmpty(S))
    {
        printf("Popped: %d\n", pop(S));
    }
    display(S);
    printf("\n");

    printf("Attempting to pop from empty stack\n");
    pop(S);
    printf("\n");

    free(S);

    return 0;
}
