#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree node structure
struct Node {
    int data;  // data of the node
    struct Node *left, *right;  // left and right references
};

// Constructor of tree node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

// Structure to store pairs for queue
struct QueueNode {
    struct Node* node;
    int verticalIndex;
};

// Queue structure to hold nodes during level order traversal
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct QueueNode* array;
};

// Function to create a queue of given capacity
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
void enqueue(struct Queue* queue, struct Node* node, int verticalIndex) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear].node = node;
    queue->array[queue->rear].verticalIndex = verticalIndex;
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

// Function to print the bottom view of the binary tree
void printBottomView(struct Node* root) {
    if (!root)
        return;

    int hash[1000];  // To store vertical index -> node data
    int leftmost = 0;  // To store the leftmost index
    int maxSize = 1000;
    for (int i = 0; i < maxSize; i++)
        hash[i] = 0;

    struct Queue* queue = createQueue(1000);  // Create a queue for level order traversal
    enqueue(queue, root, 0);  // Enqueue the root node with vertical index 0

    while (!isEmpty(queue)) {
        struct QueueNode* frontNode = dequeue(queue);
        struct Node* temp = frontNode.node;
        int ind = frontNode.verticalIndex;

        hash[ind + maxSize / 2] = temp->data;  // Store the latest vertical index -> node data
        if (ind < leftmost)
            leftmost = ind;  // Update leftmost index if needed

        if (temp->left) {
            enqueue(queue, temp->left, ind - 1);  // Enqueue left child with vertical index ind-1
        }
        if (temp->right) {
            enqueue(queue, temp->right, ind + 1);  // Enqueue right child with vertical index ind+1
        }
    }

    // Traverse and print the bottom view from leftmost to the rightmost index
    for (int i = leftmost + maxSize / 2; i < maxSize; i++) {
        if (hash[i] != 0)
            printf("%d ", hash[i]);
    }

    free(queue);
}

// Driver code
int main() {
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printf("Bottom view of the given binary tree:\n");
    printBottomView(root);

    return 0;
}

