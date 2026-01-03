#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int *table;
    int size;
} HashTable;

void initHash(HashTable *ht) {
    ht->size = MAX;
    ht->table = (int *)malloc(sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++) {
        ht->table[i] = -1;
    }
}

int hashFunction(int key) {
    return key % MAX;
}

void insertLinearProbing(HashTable *ht, int key) {
    int index = hashFunction(key);
    int i = 0;
    while (ht->table[(index + i) % MAX] != -1 && i < MAX) {
        i++;
    }
    if (i < MAX) {
        ht->table[(index + i) % MAX] = key;
    }
}

int searchLinearProbing(HashTable *ht, int key) {
    int index = hashFunction(key);
    int i = 0;
    while (ht->table[(index + i) % MAX] != key && i < MAX) {
        if (ht->table[(index + i) % MAX] == -1) {
            return -1;
        }
        i++;
    }
    return (i < MAX) ? (index + i) % MAX : -1;
}

void display(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        printf("[%d]: %d\n", i, ht.table[i]);
    }
}

int main() {
    HashTable ht;
    initHash(&ht);
    
    insertLinearProbing(&ht, 15);
    insertLinearProbing(&ht, 25);
    insertLinearProbing(&ht, 35);
    insertLinearProbing(&ht, 45);
    
    display(ht);
    
    printf("\nSearch 25: %d\n", searchLinearProbing(&ht, 25));
    printf("Search 50: %d\n", searchLinearProbing(&ht, 50));
    
    free(ht.table);
    return 0;
}
