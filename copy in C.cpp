#include <stdio.h>

typedef struct{
	int data;
	char* name;
	int prev;
} node;

int main() {
	node personA={23,"Swapneel",22};
	node personB=personA;
	
	printf("Student 2 details:\n ");
	printf("data is: %d\n ",personB.data);
	printf("Name is %s\n",personB.name);
	printf("prev is %d\n",personB.prev);
	
	return 0;
	
	
	 
}
