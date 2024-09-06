#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node in the tree
struct node* create(int new_data) {
    // Allocate memory for new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // Assign data to the node
    newNode->data = new_data;

    // Initialize left and right children as NULL
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {
    // Creating a root node with data = 10
    struct node* root = create(10);

    // You can then manually link child nodes like this:
    root->left = create(5);
    root->right = create(15);
    root->left->left=create(6);
    root->right->right=create(3);

    // Example output to verify the structure
    printf("Root Node: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);
    printf("Left Child of left child: %d\n", root->left->left->data);
    printf("Right Child: %d\n", root->right->right->data);

    return 0;
}

