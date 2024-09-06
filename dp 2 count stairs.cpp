#include<stdio.h>

int countStair(int n) {
    int dp[n+1];

    // Base cases
    dp[0] = 1;  // 1 way to stay at the ground (0th stair)
    dp[1] = 1;  // 1 way to reach the 1st stair (one step)

    // Fill the dp array for all stairs up to n
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];  // ways to reach ith stair
    }

    // Return the number of ways to reach the nth stair
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);

    int result = countStair(n);
    printf("The total number of ways is %d\n", result);
    return 0;
}

