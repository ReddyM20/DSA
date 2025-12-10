#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 8

void initialize(unsigned char *set)
{
    *set = 0;
}

void insert(unsigned char *set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return;
    *set |= (1 << element);
}

void delete(unsigned char *set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return;
    *set &= ~(1 << element);
}

int find(unsigned char set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return 0;
    return (set & (1 << element)) != 0;
}

unsigned char unionSet(unsigned char A, unsigned char B)
{
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B)
{
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B)
{
    return A & ~B;
}

void display(unsigned char set)
{
    printf("{");
    int first = 1;
    int i;
    for (i = 0; i < MAX_BITS; i++)
    {
        if (set & (1 << i))
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
    unsigned char A, B, C;

    initialize(&A);
    printf("After initialize: ");
    display(A);

    insert(&A, 1);
    printf("After insert 1: ");
    display(A);

    insert(&A, 6);
    printf("After insert 6: ");
    display(A);

    printf("Find 1: %s\n", find(A, 1) ? "Yes" : "No");
    printf("Find 3: %s\n", find(A, 3) ? "Yes" : "No");

    initialize(&B);
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("Set B: ");
    display(B);

    C = unionSet(A, B);
    printf("Union: ");
    display(C);

    C = intersection(A, B);
    printf("Intersection: ");
    display(C);

    C = difference(A, B);
    printf("Difference A-B: ");
    display(C);

    delete(&A, 6);
    printf("After delete 6: ");
    display(A);

    delete(&A, 1);
    printf("After delete 1: ");
    display(A);

    return 0;
}
