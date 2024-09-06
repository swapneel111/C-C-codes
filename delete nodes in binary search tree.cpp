//delete a node in BST Case 1: Node has no children: Simply remove the node.Case 2: Node has one child: Replace the node with its child.Case 3: Node has two children:
//Find the inorder successor (the smallest node in the right subtree) or inorder predecessor (the largest node in the left subtree).
//Replace the node's value with the successor's value.
//Recursively delete the successor.

#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* findMin(struct node* root) {
	while(root->left!=0) {
		root=root->left;//coz smallest nodes always found at leftmost position
	}
	return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root; // Base case: If the tree is empty
    }

    // Recur down the tree to find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // If the key is in the left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // If the key is in the right subtree
    } else { 
        // Node to be deleted is found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: No children (leaf node)
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: One child (right child)
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 2: One child (left child)
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Two children
        struct node* temp = findMin(root->right);  // Find the in-order successor (smallest node in the right subtree)
        root->data = temp->data;  // Replace the node's value with the in-order successor's value
        root->right = deleteNode(root->right, temp->data);  // Delete the in-order successor
    }
    
    return root;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct node* root = create(50);
    root->left = create(30);
    root->right = create(70);
    root->left->left = create(20);
    root->left->right = create(40);
    root->right->left = create(60);
    root->right->right = create(80);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
