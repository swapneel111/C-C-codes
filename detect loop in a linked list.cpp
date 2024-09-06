#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

// Function to insert a new node at the end of the linked list
struct node* insertAtEnd(struct node* head, int new_data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = new_data;
    temp->link = NULL;

    if (head == NULL) {
        return temp;
    }

    struct node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;

    return head;
}

// Function to print the linked list
void print(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->link;
    }
    printf("\n");
}

// Function to detect a loop in the linked list
int detectLoop(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;

    while (slow != NULL && fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;

        // Check if slow and fast meet
        if (slow == fast) {
            return 1; // Loop detected
        }
    }
    return 0; // No loop detected
}

// Function to create a loop in the linked list (for testing purposes)
void createLoop(struct node* head, int pos) {
    if (pos == 0) return;

    struct node* temp = head;
    struct node* loopNode = NULL;
    int count = 1;

    while (temp->link != NULL) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->link;
        count++;
    }
    temp->link = loopNode; // Creating a loop
}

int main() {
    struct node* head = NULL;

    head = insertAtEnd(head, 45);
    head = insertAtEnd(head, 98);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 42);

    printf("Original list:\n");
    print(head);

    // Creating a loop in the list for testing
    createLoop(head, 2);

    // Detecting loop
    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}

//Assume you have a linked list: 1 -> 2 -> 3 -> 4 -> 5 and you want to create a loop starting from position 3:List Traversal with Count:

//Start with count = 1, temp points to 1.Move to 2, increment count to 2.Move to 3, increment count to 3. Here, count matches pos, so loopNode is set to point to 3.
//Continue to 4, then to 5, count becomes 5.
//Creating the Loop:The temp now points to 5. Set temp->link to loopNode (which points to 3).
//Now, the list is 1 -> 2 -> 3 -> 4 -> 5 -> 3 -> ... and so on, forming a loop starting at node 3.

