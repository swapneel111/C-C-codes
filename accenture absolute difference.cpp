#include <stdio.h>
#include<math.h>

int findCount(int arr[], int length, int num, int diff) {
	int count=0;
	if(length==0) {
		return -1;
	}
	for(int i=0;i<length;i++) {
		if(abs(arr[i]-num)<=diff) {
			count++;
		}

	}
	return count;
	
}

int main() {
	int arr[]={12,3,14,56,77,13};
	int length=sizeof(arr)/sizeof(arr[0]);
	int num=13;
	int diff=2;
	int count=findCount(arr,length,num,diff);
	printf("%d",count);
	return 0;
}
