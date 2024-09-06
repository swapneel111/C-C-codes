#include <stdio.h>
#include <math.h>

// Function to extract individual digits
// of a number and store them in an array
void extractDigits(int N, int digits[], int *size) {
    // Initialize size to 0
    *size = 0;
    
    // Temporary variable to store the number
    int temp = N;
    
    // Loop to count the number of digits
    while (temp > 0) {
        temp = temp / 10;
        (*size)++;
    }
    
    // Fill the array with digits in reverse order
    for (int i = *size - 1; i >= 0; i--) {
        digits[i] = N % 10;
        N = N / 10;
    }
}

int isArmstrong(int N) {
    int digits[10];
    int size;
    int sum = 0;
    int originalN = N;
    
    // Extract digits
    extractDigits(N, digits, &size);
    
    // Calculate the sum of the digits raised to the power of the number of digits
    for (int i = 0; i < size; i++) {
        sum = sum+ pow(digits[i], size);
    }

    // Check if the sum is equal to the original number
    return (sum == originalN);
}
int main() {
    int N = 153;
    printf("N: %d\n", N);
    
    // Maximum number of digits for an integer
    int digits[10];
    int size;
    
    // Extract digits
    extractDigits(N, digits, &size);
    
    // Print extracted digits
    printf("Extracted Digits: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");
    
    if (isArmstrong(N)) {
        printf("%d is an Armstrong number.\n", N);
    } else {
        printf("%d is not an Armstrong number.\n", N);
    }
    
    return 0;
}

