#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Utility function to check if the tree is a BST
int isBSTUtil(struct node* root, int min, int max) {
    // An empty tree is a BST
    if (root == NULL)
        return 1;

    // If the current node's value violates the min/max constraint, it's not a BST
    if (root->data < min || root->data > max)
        return 0;

    // Otherwise, check the subtrees recursively, tightening the min/max constraints
    return isBSTUtil(root->left, min, root->data - 1) && 
           isBSTUtil(root->right, root->data + 1, max);
}

// Function to check if a binary tree is a BST
int isBST(struct node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct node* root = create(10);
    root->left = create(5);
    root->right = create(20);
    root->left->left = create(2);
    root->left->right = create(8);
    root->right->left = create(25);
    root->right->right = create(25);

    if (isBST(root))
        printf("The tree is a BST.\n");
    else
        printf("The tree is not a BST.\n");

    return 0;
}

