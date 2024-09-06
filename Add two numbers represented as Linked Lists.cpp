#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}


void print(struct node* node) {
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->link;
    }
    printf("\n");
}

struct node* addTwoNumbers(struct node* head,struct node* l1,struct node* l2) {
	struct node* dummy=(struct node*)malloc(sizeof(struct node));
	head=dummy;
	int carry=0;
	while(l1!=NULL||l2!=NULL) { 
		int sum=0;
		if(l1!=NULL) {
			sum+=l1->data;
			l1=l1->link;
		}
		if(l2!=NULL) {
			sum+=l2->data;
			l2=l2->link;
		}
		
		sum+=carry;
		carry=sum/10;
		head->link=createNode(sum%10);
		head=head->link;
			 
		
		
	}
	return dummy->link;
	
}

int main() {
    // Example usage:
    // List 1: 2 -> 4 -> 3 (represents 342)
    struct node* l1 = createNode(2);
    l1->link = createNode(4);
    l1->link->link = createNode(3);

    // List 2: 5 -> 6 -> 4 (represents 465)
    struct node* l2 = createNode(5);
    l2->link = createNode(6);
    l2->link->link = createNode(4);

    struct node* head = addTwoNumbers(head,l1, l2);
    print(head); // Output should be: 7 -> 0 -> 8 -> NULL (represents 807)

    // Free memory (omitted for brevity)

    return 0;
}
