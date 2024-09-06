#include <stdio.h> 

string twoSum(int arr[],int n,int sum) {
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if (i==j) continue;
			if (arr[i]+arr[j] == sum) {
				return "YES";
				printf("The two number whose sum is %d are %d and %d",sum,arr[i],arr[j]);
			}
		}
	}
	return "NO"
}

int main() {
	
	int arr[]={2,6,5,3,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=14;
	
	twoSum(arr,n,sum);
	return 0;
	
	
}
