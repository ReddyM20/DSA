#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *initialize()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue *q)
{
    return q->rear == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->rear = newNode;
        q->front = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = q->rear;
        q->front->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;

    Node *temp = q->rear;
    int value = temp->data;

    if (q->rear == q->front)
    {
        q->rear = NULL;
        q->front = NULL;
    }
    else
    {
        q->rear = q->rear->next;
        q->front->next = q->rear;
    }

    free(temp);
    return value;
}

int front(Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->rear->data;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty\n");
        return;
    }

    Node *temp = q->rear;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->rear);
    printf("\n");
}

int main()
{
    Queue *Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    printf("After enqueue: ");
    display(Q);

    enqueue(Q, 4);
    printf("After enqueue 4: ");
    display(Q);

    printf("Front: %d\n", front(Q));

    printf("Dequeued: %d\n", dequeue(Q));
    printf("After dequeue: ");
    display(Q);

    while (!isEmpty(Q))
    {
        dequeue(Q);
    }
    printf("After dequeue all: ");
    display(Q);

    free(Q);
    return 0;
}
