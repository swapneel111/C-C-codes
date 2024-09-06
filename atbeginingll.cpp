#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node* link;
};

struct node* insertAtStart(struct node* head, int new_data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));


    temp->data = new_data;
    temp->link = NULL;
    temp->link=head;
    head=temp;
    return head;
    
}


void print(struct node* node) { 
	while(node!=NULL) {
		printf("%d  ",node->data);
		node=node->link;
	}
	printf("\n");
	
}

int main() {
    // Create initial nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = 2;
    current->link = NULL;
    head->link = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 4;
    current->link = NULL;
    head->link->link->link = current;
    

    
    // Insert new node at the end
    head=insertAtStart(head, 67);
    
    
    // Print the list after insertion
    print(head);
    
    // Free the allocated memory
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
    
    return 0;
}
