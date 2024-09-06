#include <stdio.h>
#include <stdlib.h>

char *decitoNBase(int n, int num) {
    // Edge case for num being 0
    if (num == 0) {
        char *result = (char *)malloc(2 * sizeof(char)); // "0" + null terminator
        if (result == NULL) {
            return NULL;
        }
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char *res = NULL;
    int quotient = num;
    int *rem = NULL;   // Allocate space dynamically
    int remSize = 0;

    // Calculate remainders (digits in the new base)
    while (quotient != 0) {
        remSize++;
        int *temp = (int *)realloc(rem, remSize * sizeof(int));
        if (temp == NULL) {
            free(rem);  // Free previously allocated memory
            return NULL;
        }
        rem = temp;
        rem[remSize - 1] = quotient % n;
        quotient = quotient / n;
    }

    // Allocate memory for the result string
    res = (char *)malloc((remSize + 1) * sizeof(char)); // +1 for null terminator
    if (res == NULL) {
        free(rem);  // Free rem if memory allocation for res fails
        return NULL;
    }

    // Convert the remainders into the appropriate characters
    int i, j = 0;
    for (i = remSize - 1; i >= 0; i--) {
        if (rem[i] > 9) {
            res[j] = (char)(rem[i] - 10 + 'A');  // For bases greater than 10 (A, B, C...)
        } else {
            res[j] = (char)(rem[i] + '0');  // For 0-9 digits
        }
        j++;
    }
    res[j] = '\0';  // Null-terminate the string

    free(rem);  // Free the remainder array
    return res;
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);  // Take base and number as input
    char *result = decitoNBase(n, num);
    if (result != NULL) {
        printf("%s\n", result);  // Print the converted number
        free(result);  // Free the allocated memory for result
    }
    return 0;
}

