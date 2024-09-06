#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0; // Not a prime number
    }
    return 1; 
}

int primeArray(int arr[],int n) {
	int sum=0;
	int count=0;

	for(int i=0;i<n;i++) {
		if(isPrime(i)) {
			sum+=arr[i];
		}		
}
		return sum;
}

int main() {
	int arr[]={5,3,6,7,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int sum=primeArray(arr,n);
	printf("%d",sum);
	return 0;
}
