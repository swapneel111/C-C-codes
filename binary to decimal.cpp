#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int length = strlen(binary);

    // Convert each binary digit to decimal
    for (int i = 0; i < length; i++) {
        // Convert character '0' or '1' to integer 0 or 1
        int bit = binary[i] - '0';
        
        // Calculate the contribution of this bit to the decimal value
        decimal += bit * pow(2, length - 1 - i);
    }

    return decimal;
}

int main() {
    char binary[100];

    // Input binary number as a string
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    // Output the decimal equivalent
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}

