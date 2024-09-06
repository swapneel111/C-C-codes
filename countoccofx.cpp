#include <stdio.h>
#include <stdlib.h>

int countOcc(int arr[],int n,int x) {
	
	int maxElement=arr[n-1];
	int *hash=(int *)calloc(maxElement+1,sizeof(int));
	
	for(int i=0;i<n;i++) {
		hash[arr[i]]++;
	}
	
	int count=hash[x];
	
	free(hash);
	return count;
}

int main() {
	
	int arr[]={2, 2 , 3 , 3 , 3 , 3 , 4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=2;
	int count=countOcc(arr,n,x);
	printf("%d",count);
	return 0;
	
	
}
