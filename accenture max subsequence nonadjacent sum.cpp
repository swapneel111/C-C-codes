		#include <stdio.h>
		
		int max(int a, int b) {
		    return (a > b) ? a : b;
		}
		
		int findMaxSum(int arr[], int n) {
			if (n == 0) return 0;
		    if (n == 1) return arr[0];
		    
		    int dp[n];//means max subsequence sum from 0 upto nth index//last element in the array will give the max since it contains sum of subsequence from 0 to n-1
			dp[0]=arr[0];
			dp[1]=max(dp[0],arr[1]);//max of notpick and pick
			
			for(int i=2;i<n;i++) {
				int pick=arr[i]+dp[i-2];
				int notpick=0+dp[i-1];
				dp[i]=max(pick,notpick);
			}
			
			return dp[n-1];
			
		}
		
		
		int main() {
	    int arr[30];
	    int n;
	    printf("Enter the size of the array: ");
	    scanf("%d", &n);
	    if (n <= 0 || n > 30) {
	        printf("Invalid array size.\n");
	    }
	    printf("Enter the array elements: ");
	    for (int i = 0; i < n; i++) {
	        scanf("%d", &arr[i]);
	    }
	    int maxSum = findMaxSum(arr, n);
	    printf("Maximum sum of non-adjacent elements: %d\n", maxSum);
	    return 0;
	}
