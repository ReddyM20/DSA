#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element heap[MAX];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq) {
    pq->size = 0;
}

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->heap[index].priority > pq->heap[parent].priority) {
        swap(&pq->heap[index], &pq->heap[parent]);
        heapifyUp(pq, parent);
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < pq->size && pq->heap[left].priority > pq->heap[largest].priority) {
        largest = left;
    }
    
    if (right < pq->size && pq->heap[right].priority > pq->heap[largest].priority) {
        largest = right;
    }
    
    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

void enqueue(PriorityQueue *pq, int data, int priority) {
    if (pq->size < MAX) {
        pq->heap[pq->size].data = data;
        pq->heap[pq->size].priority = priority;
        heapifyUp(pq, pq->size);
        pq->size++;
    }
}

Element dequeue(PriorityQueue *pq) {
    Element result = {-1, -1};
    if (pq->size > 0) {
        result = pq->heap[0];
        pq->heap[0] = pq->heap[pq->size - 1];
        pq->size--;
        heapifyDown(pq, 0);
    }
    return result;
}

void display(PriorityQueue pq) {
    printf("[");
    for (int i = 0; i < pq.size; i++) {
        printf("(%d,%d)", pq.heap[i].data, pq.heap[i].priority);
        if (i < pq.size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    PriorityQueue pq;
    initPQ(&pq);
    
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    enqueue(&pq, 40, 3);
    
    display(pq);
    
    Element e = dequeue(&pq);
    printf("Dequeued: (%d, %d)\n", e.data, e.priority);
    
    display(pq);
    
    return 0;
}
