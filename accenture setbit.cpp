#include <stdio.h>


int countbit(int n) {
	int count=0;
	int i=0;
	
	while(n>0) {
		int digit=n%2;
		if(digit==1) {
			count+=1;
		}
		n=n/2;
		i++;
	}
	return count;
		
}

int setbit(int N) {
    int totalCount = 0;

    for (int i = 1; i <= N; i++) {
        totalCount += countbit(i); // Count set bits for each number and add to total
    }

    return totalCount; // Return the total count of set bits
}

int main() {
    int N = 4; // Example input
    printf("Total set bits from 1 to %d is: %d\n", N, setbit(N));
    return 0;
}

