#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

typedef int Set[ARRAY_SIZE];

void initialize(Set set)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        set[i] = 0;
    }
}

void insert(Set set, int element)
{
    if (element < 0 || element >= ARRAY_SIZE)
        return;
    set[element] = 1;
}

void delete(Set set, int element)
{
    if (element < 0 || element >= ARRAY_SIZE)
        return;
    set[element] = 0;
}

int find(Set set, int element)
{
    if (element < 0 || element >= ARRAY_SIZE)
        return 0;
    return set[element];
}

void unionSet(Set A, Set B, Set C)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set)
{
    printf("{");
    int first = 1;
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (set[i])
        {
            if (!first)
                printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main()
{
    Set A, B, C;

    initialize(A);
    printf("After initialize: ");
    display(A);

    insert(A, 0);
    printf("After insert 0: ");
    display(A);

    insert(A, 2);
    printf("After insert 2: ");
    display(A);

    insert(A, 7);
    printf("After insert 7: ");
    display(A);

    printf("Find 2: %s\n", find(A, 2) ? "Yes" : "No");
    printf("Find 5: %s\n", find(A, 5) ? "Yes" : "No");

    initialize(B);
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    printf("Set B: ");
    display(B);

    unionSet(A, B, C);
    printf("Union: ");
    display(C);

    intersection(A, B, C);
    printf("Intersection: ");
    display(C);

    difference(A, B, C);
    printf("Difference A-B: ");
    display(C);

    delete(A, 0);
    printf("After delete 0: ");
    display(A);

    delete(A, 7);
    printf("After delete 7: ");
    display(A);

    return 0;
}
