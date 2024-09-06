#include <stdio.h>
#include <string.h>

// Function to perform binary operations on two binary strings
void binaryOperation(char* bin1, char* bin2, char* result, char* operation) {
    int length1 = strlen(bin1);
    int length2 = strlen(bin2);

    // Ensure both binary strings are of the same length
    if (length1 != length2) {
        printf("Error: Binary strings must be of the same length.\n");
        return;
    }

    for (int i = 0; i < length1; i++) {
        // Determine the operation type without using strcmp
        if (operation[0] == 'A' && operation[1] == 'N' && operation[2] == 'D') {
            // AND operation
            result[i] = (bin1[i] == '1' && bin2[i] == '1') ? '1' : '0';
        } else if (operation[0] == 'O' && operation[1] == 'R' && operation[2] == '\0') {
            // OR operation
            result[i] = (bin1[i] == '1' || bin2[i] == '1') ? '1' : '0';
        } else if (operation[0] == 'X' && operation[1] == 'O' && operation[2] == 'R') {
            // XOR operation
            result[i] = (bin1[i] == bin2[i]) ? '0' : '1';
        } else {
            printf("Error: Invalid operation. Use AND, OR, or XOR.\n");
            return;
        }
    }

    // Null-terminate the result string
    result[length1] = '\0';
}

int main() {
    char bin1[] = "1101";
    char bin2[] = "1011";
    char result[5];  // Ensure it has enough space for the result and null terminator
    char operation[] = "XOR";

    binaryOperation(bin1, bin2, result, operation);
    printf("Result of %s operation: %s\n", operation, result);

    return 0;
}

