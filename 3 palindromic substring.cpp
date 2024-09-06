#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to find and print the three palindromic substrings
void findPalindromicSubstrings(const char* s, int len) {
    for (int i = 1; i < len - 1; i++) {
        // Check for the first substring
        if (isPalindrome(s, 0, i - 1)) {
            for (int j = i; j < len - i; j++) {
                // Check for the second and third substrings
                if (isPalindrome(s, i, i + j - 1) && isPalindrome(s, i + j, len - 1)) {
                    // Print the substrings
                    printf("%.*s\n", i, s);               // s1
                    printf("%.*s\n", j, s + i);           // s2
                    printf("%.*s\n", len - i - j, s+i+j); // s3
                    return;
                }
            }
        }
    }
    printf("Impossible\n");
}

int main() {
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    findPalindromicSubstrings(s, len);
    return 0;
}

