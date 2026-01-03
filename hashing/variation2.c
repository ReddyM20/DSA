#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} *NodePtr;

typedef struct {
    NodePtr *table;
    int size;
} HashTable;

void initHash(HashTable *ht) {
    ht->size = MAX;
    ht->table = (NodePtr *)malloc(sizeof(NodePtr) * MAX);
    for (int i = 0; i < MAX; i++) {
        ht->table[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % MAX;
}

void insertChaining(HashTable *ht, int key) {
    int index = hashFunction(key);
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = key;
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

int searchChaining(HashTable *ht, int key) {
    int index = hashFunction(key);
    NodePtr temp = ht->table[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
    }
    return -1;
}

void display(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        printf("[%d]: ", i);
        NodePtr temp = ht.table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht;
    initHash(&ht);
    
    insertChaining(&ht, 15);
    insertChaining(&ht, 25);
    insertChaining(&ht, 35);
    insertChaining(&ht, 45);
    
    display(ht);
    
    printf("\nSearch 25: %d\n", searchChaining(&ht, 25));
    printf("Search 50: %d\n", searchChaining(&ht, 50));
    
    return 0;
}
