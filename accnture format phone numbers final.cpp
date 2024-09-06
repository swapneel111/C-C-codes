#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define PHONE_LENGTH 10

// Function to remove prefix and get the last 10 digits
void formatNumber(char* number, char* formatted) {
    int len = strlen(number);

    // If the number starts with '+91', skip the first 3 characters
    if (strncmp(number, "+91", 3) == 0) {
        strncpy(formatted, number + 3, PHONE_LENGTH);
    }
    // If the number starts with '91', skip the first 2 characters
    else if (strncmp(number, "91", 2) == 0) {
        strncpy(formatted, number + 2, PHONE_LENGTH);
    }
    // If the number starts with '0', skip the first character
    else if (number[0] == '0') {
        strncpy(formatted, number + 1, PHONE_LENGTH);
    }
    // Otherwise, take the last 10 digits as is
    else {
        strncpy(formatted, number, PHONE_LENGTH);
    }
    formatted[PHONE_LENGTH] = '\0';  // Null-terminate the string
}

// Function to format and print the numbers
void printFormattedNumbers(char numbers[MAX_NUMBERS][PHONE_LENGTH + 1], int n) {
    for (int i = 0; i < n; i++) {
        printf("+91 %.*s %.*s\n", 5, numbers[i], 5, numbers[i] + 5);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid number of entries\n");
        return 1;
    }

    char numbers[MAX_NUMBERS][PHONE_LENGTH + 1];  // Store formatted numbers

    // Read and format the numbers
    for (int i = 0; i < n; i++) {
        char input[20];
        scanf("%s", input);

        // Format to get the last 10 digits
        formatNumber(input, numbers[i]);
    }

    // Print the formatted numbers
    printFormattedNumbers(numbers, n);

    return 0;
}

