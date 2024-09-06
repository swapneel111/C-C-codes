#include <stdio.h>
#include <string.h>

// Define the size of the alphabet (26 letters)
#define ALPHABET_SIZE 26

int main() {
    char str[] = "abcdabefc";
    int hash[ALPHABET_SIZE] = {0}; // Initialize array to 0 for all letters
    
    // Calculate the frequency of each character in the string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            hash[str[i] - 'a']++;
        }
    }

    // Queries
    char queries[] = {'a', 'c', 'z'};
    int num_queries = sizeof(queries) / sizeof(queries[0]);

    // Answer each query
    for (int i = 0; i < num_queries; i++) {
        char query = queries[i];
        if (query >= 'a' && query <= 'z') {
            printf("Character '%c' appears %d times\n", query, hash[query - 'a']);
        } else {
            printf("Character '%c' is out of range\n", query);
        }
    }

    return 0;
}

