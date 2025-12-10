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

bool isFull(Queue *q)
{
    return false;
}

bool isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot dequeue from empty queue.\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Nothing at front.\n");
        return -1;
    }

    return q->front->data;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (front to rear): ");

    Node *temp = q->front;

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
    Queue *Q = initialize();

    printf("Queue Operations Demo\n\n");

    printf("Is queue empty? %s\n\n", isEmpty(Q) ? "Yes" : "No");

    printf("Enqueuing elements\n");
    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    display(Q);
    printf("\n");

    printf("Enqueuing 4\n");
    enqueue(Q, 4);
    display(Q);
    printf("\n");

    printf("Front operation\n");
    int frontValue = front(Q);
    if (frontValue != -1)
    {
        printf("Front element: %d\n", frontValue);
    }
    display(Q);
    printf("\n");

    printf("Dequeue operation\n");
    int dequeuedValue = dequeue(Q);
    if (dequeuedValue != -1)
    {
        printf("Dequeued value: %d\n", dequeuedValue);
    }
    display(Q);
    printf("\n");

    printf("Is queue full? %s\n\n", isFull(Q) ? "Yes" : "No");

    printf("Dequeuing all elements\n");
    while (!isEmpty(Q))
    {
        printf("Dequeued: %d\n", dequeue(Q));
    }
    display(Q);
    printf("\n");

    printf("Attempting to dequeue from empty queue\n");
    dequeue(Q);
    printf("\n");

    free(Q);

    return 0;
}
