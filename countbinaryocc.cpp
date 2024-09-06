#include <stdio.h>

int findFirstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int firstOccurrence = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            firstOccurrence = mid;
            high = mid - 1;  // Look for earlier occurrences
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return firstOccurrence;
}

int findLastOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int lastOccurrence = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            lastOccurrence = mid;
            low = mid + 1;  // Look for later occurrences
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return lastOccurrence;
}

int countOccurrencesUsingBinarySearch(int arr[], int n, int x) {
    int first = findFirstOccurrence(arr, n, x);
    if (first == -1) {
        return 0;
    }
    int last = findLastOccurrence(arr, n, x);
    return last - first + 1;
}

int main() {
	int arr[] = {2, 2, 2, 3, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    
    int count = countOccurrencesUsingBinarySearch(arr, n, x);
    printf("Count of %d: %d\n", x, count);
    return 0;
}
