#include <stdio.h>
#define MAX_SIZE 100

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}	
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);

    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

