#include <stdio.h>
#include <string.h>

char* checkPalindrome(char *str, char *reverse) {
    int m = strlen(str);
    
    // Fill the reverse array with the reversed string
    for(int i = 0; i < m; i++) {
        reverse[i] = str[m - i - 1];
    }
    
    reverse[m] = '\0'; // Null-terminate the reverse string
    
    return reverse;
}

int main() {
    char str[] = "chehc";
    int m = strlen(str);
    char reverse[m+1]; // Allocate memory for the reverse string including null terminator
    
    checkPalindrome(str, reverse);
    
    // Compare the original string with its reverse
    if (strcmp(str, reverse) == 0) {
        printf("The string is a palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    
    return 0;
}

