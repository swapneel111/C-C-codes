#include <stdio.h>
#include <stdlib.h>

int findAverage(int N,int P) {
	int* result=(int*)malloc((P+1)*sizeof(int));
	int sum=0;
	int average;
	for(int i=1;i<=P;i++) {
		result[i]=N*i;
	}
	for	(int i=1;i<=P;i++) {
		sum+=result[i];
	}
	average=sum/P;
	
	free(result);
	return average;

}

int main() {
    int N = 3, P = 5;
    int avg = findAverage(N, P);
    
    if (avg != -1) {
        printf("The average is: %d\n", avg);
    }
    
    return 0;
}
