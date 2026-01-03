#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *Tree;

typedef struct qnode {
    Tree treeNode;
    struct qnode *next;
} *QueueNode;

typedef struct {
    QueueNode front;
    QueueNode rear;
} Queue;

Tree createNode(int data) {
    Tree newNode = (Tree)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, Tree node) {
    QueueNode newNode = (QueueNode)malloc(sizeof(struct qnode));
    if (newNode != NULL) {
        newNode->treeNode = node;
        newNode->next = NULL;
        if (q->rear == NULL) {
            q->front = q->rear = newNode;
        } else {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

Tree dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode temp = q->front;
    Tree node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}

void bfs(Tree T) {
    if (T == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, T);
    
    while (!isEmpty(q)) {
        Tree current = dequeue(&q);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
}

void dfs(Tree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        dfs(T->left);
        dfs(T->right);
    }
}

int main() {
    Tree root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("BFS: ");
    bfs(root);
    printf("\n");
    
    printf("DFS: ");
    dfs(root);
    printf("\n");
    
    return 0;
}
