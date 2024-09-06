#include <stdio.h>

int findDivisors(int n) {
	for(int i=1;i<=n;i++) {
		if(n%i==0) {
			printf("The divisor is %d\n",i);
			
		}
	}
	
	
}

int main() {
	int n=985;
	findDivisors(n);
	
	return 0;
}

