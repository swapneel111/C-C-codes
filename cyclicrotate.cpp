#include <stdio.h>

void cyclicRotate(int arr[],int n,int k) {

	k=k%n;
	for (int i=n-k;i<n;i++) {
		printf("%d",arr[i]);
	}
	
	for(int i=0;i<n-k;i++) {
		printf("%d",arr[i]);
	}
	
	printf("\n");
	
}



int main() {
	int arr[]={10,20,30,40,50};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=2;
	cyclicRotate(arr,n,k);
	
	int arr1[]={10,20,30,40};
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	int k1=1;
	cyclicRotate(arr1,n1,k1);
	
	
	return 0;
	
}

