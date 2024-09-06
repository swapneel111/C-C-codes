#include <stdio.h>

// Function to add two binary numbers without using +
int binaryAdd(int a, int b) {
    while (b != 0) {
        int carry = a & b;   // Calculate the carry bits
        a = a ^ b;           // Sum without carry
        b = carry << 1;      // Shift carry to the next higher bit
    }
    return a;
}

int main() {
    int a = 5; // Binary: 101
    int b = 9; // Binary: 1001
    int sum = binaryAdd(a, b);
    printf("Sum of %d and %d is: %d\n", a, b, sum);
    return 0;
}

