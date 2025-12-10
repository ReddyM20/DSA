#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct
{
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V)
{
    int i;
    V->avail = 0;
    for (i = 0; i < MAX - 1; i++)
    {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap *V)
{
    int index = V->avail;
    if (index != -1)
    {
        V->avail = V->H[V->avail].next;
    }
    return index;
}

void deallocSpace(VHeap *V, int index)
{
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(List *L, VHeap *V, int elem)
{
    int idx = allocSpace(V);
    if (idx == -1)
        return;
    V->H[idx].elem = elem;
    V->H[idx].next = *L;
    *L = idx;
}

void insertLast(List *L, VHeap *V, int elem)
{
    int idx = allocSpace(V);
    if (idx == -1)
        return;
    V->H[idx].elem = elem;
    V->H[idx].next = -1;

    if (*L == -1)
    {
        *L = idx;
    }
    else
    {
        int *trav = L;
        while (V->H[*trav].next != -1)
        {
            trav = &(V->H[*trav].next);
        }
        V->H[*trav].next = idx;
    }
}

void insertPos(List *L, VHeap *V, int elem, int pos)
{
    int idx = allocSpace(V);
    if (idx == -1)
        return;
    V->H[idx].elem = elem;

    if (pos == 0)
    {
        V->H[idx].next = *L;
        *L = idx;
    }
    else
    {
        int *trav = L;
        int i;
        for (i = 0; i < pos - 1 && *trav != -1; i++)
        {
            trav = &(V->H[*trav].next);
        }
        V->H[idx].next = V->H[*trav].next;
        V->H[*trav].next = idx;
    }
}

void insertSorted(List *L, VHeap *V, int elem)
{
    int idx = allocSpace(V);
    if (idx == -1)
        return;
    V->H[idx].elem = elem;

    int *trav = L;
    while (*trav != -1 && V->H[*trav].elem < elem)
    {
        trav = &(V->H[*trav].next);
    }
    V->H[idx].next = *trav;
    *trav = idx;
}

void delete(List *L, VHeap *V, int elem)
{
    int *trav = L;
    while (*trav != -1 && V->H[*trav].elem != elem)
    {
        trav = &(V->H[*trav].next);
    }
    if (*trav != -1)
    {
        int temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(List *L, VHeap *V, int elem)
{
    int *trav = L;
    while (*trav != -1)
    {
        if (V->H[*trav].elem == elem)
        {
            int temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        }
        else
        {
            trav = &(V->H[*trav].next);
        }
    }
}

void display(List L, VHeap V)
{
    if (L == -1)
    {
        printf("Empty\n");
        return;
    }
    int trav = L;
    while (trav != -1)
    {
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}

int main()
{
    VHeap V;
    List L = -1;
    initialize(&V);

    insertFirst(&L, &V, 3);
    insertFirst(&L, &V, 1);
    printf("After insertFirst: ");
    display(L, V);

    insertLast(&L, &V, 5);
    insertLast(&L, &V, 7);
    printf("After insertLast: ");
    display(L, V);

    insertPos(&L, &V, 4, 2);
    printf("After insertPos: ");
    display(L, V);

    List L2 = -1;
    insertSorted(&L2, &V, 10);
    insertSorted(&L2, &V, 5);
    insertSorted(&L2, &V, 15);
    insertSorted(&L2, &V, 8);
    printf("Sorted list: ");
    display(L2, V);

    delete(&L, &V, 4);
    printf("After delete: ");
    display(L, V);

    insertLast(&L, &V, 5);
    insertLast(&L, &V, 5);
    printf("With duplicates: ");
    display(L, V);

    deleteAllOccurrence(&L, &V, 5);
    printf("After deleteAll: ");
    display(L, V);

    return 0;
}
