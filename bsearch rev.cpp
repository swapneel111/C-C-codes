#include <stdio.h> 

int binarySearch(int arr[],int low,int high,int x) {
	
	
	if(high>=low) {	
		
	
		int mid=(low+(high-low)/2);
	
		if(arr[mid]>x) {
			return binarySearch(arr,low,mid-1,x);
	}
		else if (arr[mid]<x) {
			return binarySearch(arr,mid+1,high,x);
		
	}
		else if(arr[mid]==x) {
			return mid;
	}
																																																																																																																																																																																																																																																																																																																																																																																																																																																			
}
return -1;
}

int main() {
	int arr[]={3, 4, 6, 7, 9, 12, 16, 17};
	int x=9;
	int n=sizeof(arr)/sizeof(arr[0]);
	int result=binarySearch(arr,0,n-1,9);
	
	if(result==-1) {
		printf("No such element found");
	}
	else {
		printf("The element %d is found at %d index",x,result);
	}
	return 0;
}
