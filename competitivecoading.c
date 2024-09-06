#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{	int arr[5],n=0,i;
	
	printf("Enter the interger values: ");
	for(i=0; i<5; ++i)
	scanf("%d", &arr[i]);
	for(i=0;i<5; i++)
	{	
		if (n<arr[i])
			n=arr[i];
		
		else
			(n<3)&&(n>2)
			
		
	}
	printf("The value is: %d", n);

}


