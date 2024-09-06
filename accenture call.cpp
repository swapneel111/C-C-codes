#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000
#define PHONE_LENGTH 10

// Function to remove prefix and get the last 10 digits
char* formatNumber(char* number) {
    int len = strlen(number);
    
    // If the number starts with '+91', skip the first 3 characters
    if (strncmp(number, "+91", 3) == 0) {
        return number + 3;
    }

    // If the number starts with '91', skip the first 2 characters
    if (strncmp(number, "91", 2) == 0) {
        return number + 2;
    }

    // If the number starts with '0', skip the first character
    if (number[0] == '0') {
        return number + 1;
    }

    // Otherwise, return the number as is (assuming it is already 10 digits)
    return number;
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    char* numA = *(char**)a;
    char* numB = *(char**)b;
    return strcmp(numA, numB);
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

    char numbers[MAX_NUMBERS][PHONE_LENGTH + 1];  // Store formatted numbers

    // Read and format the numbers
    for (int i = 0; i < n; i++) {
        char input[20];
        scanf("%s", input);

        // Format to get the last 10 digits
        char* formatted = formatNumber(input);

        // Store the formatted number in our array
        strncpy(numbers[i], formatted, PHONE_LENGTH);
        numbers[i][PHONE_LENGTH] = '\0';  // Null-terminate the string
    }

    // Sort the numbers using qsort
    qsort(numbers, n, sizeof(numbers[0]), compare);

    // Print the formatted numbers
    printFormattedNumbers(numbers, n);

    return 0;
}

