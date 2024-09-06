#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node* link;
};

void insertAtEnd(struct node* head, int new_data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = NULL;
    ptr=head;

    temp->data = new_data;
    temp->link = NULL;
    
    // Traverse to the end of the list
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    
    // Insert the new node at the end
    ptr->link = temp;
}

struct node* del_end(struct node* head) {
	
	if(head==NULL) 
		printf("List is empty");
	else if(head->link==NULL) {
		free(head);
		head=NULL;
	}
	
	else{
	
		struct node* temp=head;
		struct node* temp2=head;
		while(temp->link!=NULL) {
		temp2=temp;
		temp=temp->link;
		
	}
	temp2->link=NULL;
	free(temp);
	temp=NULL;
}
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
	
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	
	insertAtEnd(head,98);
	insertAtEnd(head,3);
	
	head=del_end(head);
	print(head);
	
	return 0;
	
}
