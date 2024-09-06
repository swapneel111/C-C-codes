#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 20  // Max length to accommodate hyphens
void remove_newline(char *s) {
    // Find the length of the string
    size_t len = strlen(s);

    // Check if the last character is a newline
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0'; // Replace newline with null terminator
    }
}

void check(char *s) {
    int len = strlen(s);
    
    if(len != 19) {
    	printf("Invalid");
	} 

    // Check for correct length and hyphen positions
    if (s[4] != '-' || s[9] != '-' || s[14] != '-') {
        printf("Invalid\n");
        return;
    }

    // Check for digits and invalid characters
    for (int i = 0; i < len; i++) {
        if (i != 4 && i != 9 && i != 14) {
            if (!isdigit(s[i])) {
                printf("Invalid\n");
                return;
            }
        }
    }

    printf("Valid\n");
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume newline character after the integer input

    while (n--) {
        char s[MAX_LENGTH];
        fgets(s, sizeof(s), stdin);

        // Remove newline character from fgets
        remove_newline(s);

        check(s);
    }

    return 0;
}

