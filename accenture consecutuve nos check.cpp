#include <stdio.h>
#include <limits.h>

int find_min(int arr[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int find_max(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}



bool areConsecutive(int arr[], int n) {
	int min=find_min(arr,n);
	int max=find_max(arr,n);
	int visited[n];
	
	if (max - min != n - 1) {
        return false;
    }
	
	
	for(int i=0;i<n;i++){
		visited[i]=false;
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

