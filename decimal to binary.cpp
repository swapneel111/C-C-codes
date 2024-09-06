#include <stdio.h>

void decimalToBinary(int n) {
    int binaryNum[32]; // Array to store binary number
    int i = 0;

    // Edge case for 0
    if (n == 0) {
        printf("0");
        return;
    }

    // Process the decimal number until it becomes 0
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int main() {
    int n;

    // Input from user
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert decimal to binary and print the result
    printf("Binary equivalent: ");
    decimalToBinary(n);

    return 0;
}

