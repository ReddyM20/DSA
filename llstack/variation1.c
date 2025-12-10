#include <stdio.h>
#include <stdlib.h>

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

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
        return -1;

    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int peek(Stack *s)
{
    if (isEmpty(s))
        return -1;
    return s->top->data;
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty\n");
        return;
    }

    Node *temp = s->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Stack *S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 5);
    printf("After push: ");
    display(S);

    push(S, 4);
    printf("After push 4: ");
    display(S);

    printf("Peek: %d\n", peek(S));

    printf("Popped: %d\n", pop(S));
    printf("After pop: ");
    display(S);

    while (!isEmpty(S))
    {
        pop(S);
    }
    printf("After pop all: ");
    display(S);

    free(S);
    return 0;
}
