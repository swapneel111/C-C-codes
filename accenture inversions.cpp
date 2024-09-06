#include <stdio.h>

int merge(int arr[], int low, int mid, int high, int temp[]) {
    int left = low;
    int right = mid + 1;
    int k = low;
    int invCount = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
            invCount += (mid+1-left);
        }
    }
    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= high) {
        temp[k++] = arr[right++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}
int mergeSort(int arr[], int low, int high, int temp[]) {
    int invCount = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        invCount += mergeSort(arr, low, mid, temp);
        invCount += mergeSort(arr, mid + 1, high, temp);  
        invCount += merge(arr, low, mid, high, temp);
    }
    return invCount;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {8,1,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];

    printf("Before Sorting Array:\n");
    printArray(arr, n);

    int inversionCount = mergeSort(arr, 0, n - 1, temp);

    printf("After Sorting Array:\n");
    printArray(arr, n);
    printf("Total number of inversions: %d\n", inversionCount);

    return 0;
}

