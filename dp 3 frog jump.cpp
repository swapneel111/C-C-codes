#include <stdio.h>
#include <math.h>

int min(int a ,int b) {
	return (a<b) ? a:b;
}

int countStairs(int height[],int N) {
	int dp[N];
	
	dp[0]=0;
	dp[1]=dp[0]+abs(height[1]-height[0]);
	
	
	for(int i=2;i<=N-1;i++) {
		int left=dp[i-1]+abs(height[i]-height[i-1]);
		int right=dp[i-2]+abs(height[i]-height[i-2]);
		dp[i]=min(left,right);
	}
	
	return dp[N-1];
}

int main() {
	int N;
	scanf("%d",&N);
	int height[N];
	for(int i=0;i<N;i++) {
		scanf("%d",&height[i]);
	}
	
	int minimum=countStairs(height,N);
	printf("%d",minimum);
	return 0;
	
}
