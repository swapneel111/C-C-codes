#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of unique paths
int uniquePaths(int m, int n) {
    // Dynamically allocate a 2D array for DP
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize the first row and first column with 1
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1; // Only 1 way to reach any cell in the first column
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1; // Only 1 way to reach any cell in the first row
    }

    // Fill the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // From top and left
        }
    }

    // The result is in the bottom-right corner
    int result = dp[m - 1][n - 1];

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

// Main function
int main() {
    int m, n;

    // Input values for m and n
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    // Call the function and display the result
    int result = uniquePaths(m, n);
    printf("Number of unique paths: %d\n", result);

    return 0;
}

