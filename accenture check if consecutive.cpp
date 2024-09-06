#include <stdio.h>
#include <stdbool.h>

// Function to find the minimum and maximum elements in an array
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to check if the array contains consecutive integers
bool areConsecutive(int arr[], int n) {
    int min, max;
    findMinMax(arr, n, &min, &max);
    
    // Check if the difference between max and min equals n-1
    if (max - min != n - 1) {
        return false;
    }

    // Create an auxiliary array to check for duplicates
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Mark visited elements
    for (int i = 0; i < n; i++) {
        if (visited[arr[i] - min] == true) {
            return false; // If already visited, the element is a duplicate
        }
        visited[arr[i] - min] = true;
    }
    
    return true;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (areConsecutive(arr, n)) {
        printf("Array elements are consecutive: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Array elements are not consecutive.\n");
    }

    return 0;
}

