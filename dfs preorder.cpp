#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack node structure
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new stack node
struct StackNode* newStackNode(struct Node* treeNode) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->treeNode = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a tree node onto the stack
void push(struct StackNode** root, struct Node* treeNode) {
    struct StackNode* stackNode = newStackNode(treeNode);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop a tree node from the stack
struct Node* pop(struct StackNode** root) {
    if (*root == NULL) return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct Node* popped = temp->treeNode;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// DFS using stack (iterative approach)
void dfs(struct Node* root) {
    if (root == NULL) return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        // Push right and then left child to stack
        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

// Function to take user input to build the binary tree
struct Node* buildTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* root = newNode(data);

    printf("Enter left child of %d\n", data);
    root->left = buildTree();

    printf("Enter right child of %d\n", data);
    root->right = buildTree();

    return root;
}

// Driver code
int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    printf("DFS (Preorder) Traversal using stack:\n");
    dfs(root);

    return 0;
}
-
