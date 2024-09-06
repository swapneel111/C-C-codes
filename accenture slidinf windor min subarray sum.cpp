#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int* minSubarraySum(int arr[], int n, int k, int* ansStart, int* ansEnd) {
    int sum = 0, minSum = INT_MAX;

    // Calculate the sum of the first subarray of size k
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    minSum = sum;
    *ansStart = 0;
    *ansEnd = k - 1;

    // Slide the window across the array
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        if (sum < minSum) {
            minSum = sum;
            *ansStart = i - k + 1; // Adjust to correct start of subarray
            *ansEnd = i; // End of subarray is the current index
        }
    }

    // Allocate memory and store the result subarray
    int *result = (int*)malloc(k * sizeof(int));
    for (int i = *ansStart; i <= *ansEnd; i++) {
        result[i - *ansStart] = arr[i];
    }

    return result;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int ansStart = -1, ansEnd = -1;
    int* result = minSubarraySum(arr, n, k, &ansStart, &ansEnd);

    for (int i = 0; i < k; ++i)
        printf("%d ", result[i]);
    printf("\n");

    free(arr);
    free(result);
    
    return 0;
}

