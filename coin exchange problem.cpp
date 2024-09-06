#include <stdio.h>

int coinExchange(int coins[],int N,int sum) {
	int dp[N+1][sum+1];
	
	for(int i=0;i<N;i++) {
		dp[i][0]=1;
	}
	 for (int j = 1; j <= sum; j++) {
        dp[0][j] = 0;  // No way to make a positive sum with 0 coins
    }
	

    // Fill the dp table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];  // Ways to make sum j without using the i-th coin
            if (j >= coins[i-1]) {
                dp[i][j] += dp[i][j - coins[i-1]];  // Add ways to make sum j using the i-th coin
            }
        }
    }
	return dp[N][sum];
	
}

int main() {
	int sum=4;
	int coins[]={1,2,3};
	int N=(sizeof(coins)/sizeof(coins[0]));
	int combo=coinExchange(coins,N,sum);
	printf("%d",combo);
	return 0;
}
