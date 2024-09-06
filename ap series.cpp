#include <stdio.h>

int aP(int a,int n, int d,int arr[]) {

 	int sum=0;
	for(int i=0;i<n;i++) {
		arr[i]=a+(i)*d;
	}
	
	for(int i=0;i<n;i++) {
		sum+=arr[i];
	}
	
return sum;	
	
}

int main() {
	int n=6;
	int arr[n];
	int d=3;
	int a=5;
	int k=3;
	int sum;
	sum=aP(a,n,d,arr);
	printf("\n");
	printf("%d",sum);
	return 0;
}
