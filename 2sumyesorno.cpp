#include <stdio.h>

// Function to check if there are two numbers in the array that sum to 'sum'
const char* twoSum(int arr[], int n, int sum) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
            	
                printf("The two numbers whose sum is %d are %d and %d\n", sum, arr[i], arr[j]);
                return "YES";
                
            }
        }
    }
    return "NO";
}

int main() {
    int arr[] = {2, 6, 5, 3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 14;

    // Call twoSum and print the result
    const char* result = twoSum(arr, n, sum);
    printf("Result: %s\n", result);

    return 0;
}

