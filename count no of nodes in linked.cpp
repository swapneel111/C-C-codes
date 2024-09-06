#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

void printList(struct node* node) {
	while(node!=NULL) {
		printf("%d ",node->data);
		node=node->link;
	}
}

void count_of_nodes(struct node* head) {
	int count;
	if (head==NULL) {
		printf("Linked List is empty");
	}
	struct node* ptr=head;
	while(ptr!=NULL) {
		count++;
		ptr=ptr->link;
	}
	printf("Total no of nodes is: %d\n",count);
}

int main() {

	struct node* head=(struct node* ) malloc (sizeof(struct node));
	head->data=45;
	head->link=NULL;
	struct node* current=(struct node* ) malloc (sizeof(struct node));
	current->data=98;
	current->link=NULL;
	head->link=current;
	current=(struct node* ) malloc (sizeof(struct node));
	current->data=3;
	current->link=NULL;
	head->link->link=current;
	printList(head);
	count_of_nodes(head);
	return 0;
}
