#include <stdio.h>

// Function to rearrange the array by signs
void RearrangebySign(int arr[], int n, int result[]) {
    // Temporary arrays to hold positive and negative numbers
    int pos[n], neg[n];
    int posIndex = 0, negIndex = 0;
    
    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos[posIndex++] = arr[i];
        } else {
            neg[negIndex++] = arr[i];
        }
    }
    
    // Rearrange elements: positives on even indices, negatives on odd indices.
    int index = 0;
    for (int i = 0; i < posIndex; i++) {
        if (index < n) result[index++] = pos[i]; // Place positive element
        if (index < n) result[index++] = neg[i]; // Place negative element
    }
    
    // If any remaining positives or negatives, add them to the result

}

int main() {
    // Array initialization
    int n = 4;
    int A[] = {1, 2, -4, -5};
    int result[n]; // To store the rearranged array

    // Call the function to rearrange by sign
    RearrangebySign(A, n, result);

    // Print the rearranged array
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

