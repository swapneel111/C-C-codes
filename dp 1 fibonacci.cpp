#include <stdio.h>

int main() {
	int n=5;
	int dp[n+1];
	
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++) {
		dp[i]=dp[i-1]+dp[i-2];
	}
	
	printf("the fib series is: ");
	for(int n=0;n<=5;n++) {
	
		printf("%d",dp[n]);
		
	}
	return 0;
}
