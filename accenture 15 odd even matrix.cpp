#include <stdio.h>

int swap(int *a,int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
	int arr[100];
	int length;
	int odd[50];
	int even[50];
	int oddlen,evenlen;
	
	printf("Enter the length of the array: ");
	scanf("%d", &length);
	
	for(int i=0;i<length;i++) {
		printf("Enter the %d element of the array :",i);
		scanf("%d",&arr[i]);	
	}
	if(length%2==0) {
		int oddlen=length/2;
		int evenlen=length/2;
	}else {
    	oddlen = length / 2;
    	evenlen = (length / 2) + 1;
	}
	
	for (int i = 0; i < length; i++) {
    	if (i % 2 == 0) {
        	even[i / 2] = arr[i];
    	} else {
        	odd[i / 2] = arr[i];
    	}
	}
	
	for(int i=0;i<evenlen-1;i++) {
		for(int j=i+1;j<evenlen;j++) {
			if(even[i]>even[j]) {
			
				swap(&even[i],&even[j]);
		}
	}
	}
	
	for(int i=0;i<oddlen-1;i++) {
		for(int j=i+1;j<oddlen;j++) {
			if(odd[i]>odd[j]) {
				
				swap(&odd[i],&odd[j]);
		}
	}
}
	
	printf("\nSorted even array: ");
	for (int i = 0; i < evenlen; i++) {
    	printf("%d ", even[i]);
	}
	printf("\n");

	printf("Sorted odd array: ");
	for (int i = 0; i < oddlen; i++) {
    	printf("%d ", odd[i]);
	}
	printf("\n");
	
	int sum=even[evenlen-2]+odd[oddlen-2];
	printf("%d",sum);
	return 0;
	

}
