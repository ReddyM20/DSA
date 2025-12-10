#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 8

typedef struct
{
    unsigned char field : 8;
} Set;

void initialize(Set *set)
{
    set->field = 0;
}

void insert(Set *set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return;
    set->field |= (1 << element);
}

void delete(Set *set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return;
    set->field &= ~(1 << element);
}

int find(Set set, int element)
{
    if (element < 0 || element >= MAX_BITS)
        return 0;
    return (set.field & (1 << element)) != 0;
}

Set unionSet(Set A, Set B)
{
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set intersection(Set A, Set B)
{
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set difference(Set A, Set B)
{
    Set result;
    result.field = A.field & ~B.field;
    return result;
}

void display(Set set)
{
    printf("{");
    int first = 1;
    int i;
    for (i = 0; i < MAX_BITS; i++)
    {
        if (set.field & (1 << i))
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

    initialize(&A);
    printf("After initialize: ");
    display(A);

    insert(&A, 0);
    printf("After insert 0: ");
    display(A);

    insert(&A, 4);
    printf("After insert 4: ");
    display(A);

    insert(&A, 5);
    printf("After insert 5: ");
    display(A);

    printf("Find 4: %s\n", find(A, 4) ? "Yes" : "No");
    printf("Find 3: %s\n", find(A, 3) ? "Yes" : "No");

    initialize(&B);
    insert(&B, 2);
    insert(&B, 5);
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

    delete(&A, 5);
    printf("After delete 5: ");
    display(A);

    delete(&A, 4);
    printf("After delete 4: ");
    display(A);

    return 0;
}
