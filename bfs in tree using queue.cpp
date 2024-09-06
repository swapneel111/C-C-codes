#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node structure
struct QueueNode {
    struct Node* node;
    int level;
};

// Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct QueueNode* array;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct QueueNode*)malloc(queue->capacity * sizeof(struct QueueNode));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add a node to the queue
void enqueue(struct Queue* queue, struct Node* node, int level) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear].node = node;
    queue->array[queue->rear].level = level;
    queue->size = queue->size + 1;
}

// Function to remove a node from the queue
struct QueueNode dequeue(struct Queue* queue) {
    struct QueueNode item = {NULL, 0};
    if (isEmpty(queue))
        return item;
    item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to print the level order traversal of the binary tree
void printLevelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue(1000); // Create a queue with a capacity of 1000

    // Enqueue the root node with level 0
    enqueue(queue, root, 0);

    while (!isEmpty(queue)) {
        struct QueueNode queueNode = dequeue(queue);
        struct Node* node = queueNode.node;
        int level = queueNode.level;

        // Print the node's data and its level
        printf("Node: %d at Level: %d\n", node->data, level);

        // Enqueue the left child with level + 1
        if (node->left != NULL) {
            enqueue(queue, node->left, level + 1);
        }

        // Enqueue the right child with level + 1
        if (node->right != NULL) {
            enqueue(queue, node->right, level + 1);
        }
    }

    free(queue->array);
    free(queue);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printLevelOrder(root);

    return 0;
}

