#include <stdio.h>
#include <stdlib.h>

int fmax(int a, int b) {
    return (a > b) ? a : b;
}

// A binary tree node
struct Node {
    int data;
    struct Node* left, *right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// A utility function to compute the height of a tree
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return 1 + fmax(height(node->left), height(node->right));
}

// Function to compute the diameter of a binary tree
int diameter(struct Node* tree) {
    if (tree == NULL)
        return 0;

    // Get the height of left and right sub-trees
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    // Get the diameter of left and right sub-trees
    int leftDiameter = diameter(tree->left);
    int rightDiameter = diameter(tree->right);

    // Return max of the following three:
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return fmax(leftHeight + rightHeight + 1, fmax(leftDiameter, rightDiameter));
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of the given binary tree is %d\n", diameter(root));

    return 0;
}
//O[N^2]->TC
//
//To calculate the diameter of the tree rooted at node 1, we need to consider:

//The diameter passing through the root (node 1).
//The diameter of the left subtree (rooted at node 2).
//The diameter of the right subtree (rooted at node 3).
//ameter Calculation Steps:
//Calculate the Height of the Subtrees:
//For node 4 and node 5, the height is 1 because they are leaf nodes.For node 2, the height is 2 (because its height is 1 + max(height(4), height(5))).
//For node 3, the height is 1 (as it’s a leaf node).Calculate the Diameter Passing Through the Root Node (1):
//The diameter passing through node 1 is the sum of the heights of its left and right subtrees plus one (for the root node itself):

//Height of left subtree (rooted at node 2) is 2.Height of right subtree (rooted at node 3) is 1.
//Diameter passing through node 1 = leftHeight + rightHeight + 1 = 2 + 1 + 1 = 4.
//Calculate the Diameter of Subtrees:

//Diameter of left subtree (rooted at node 2):The left subtree (rooted at node 2) has height 2.Diameter passing through node 2 (considering its children 4 and 5) = leftHeight + rightHeight + 1 = 1 + 1 + 1 = 3.
//Diameter of subtree rooted at node 2 is 3 (since it’s the maximum of diameters of left and right subtrees and the path passing through node 2).
//Diameter of right subtree (rooted at node 3):Node 3 is a leaf, so its diameter is 1.Final Diameter Calculation:The diameter of the entire tree rooted at node 1 is the maximum of:
//Diameter passing through the root (node 1): 4
//Diameter of left subtree (rooted at node 2): 3
//Diameter of right subtree (rooted at node 3): 1
//Thus, the final diameter of the tree is:max(4, max(3, 1)) = 4.
