#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 20  // Max length to accommodate hyphens

void check(char *s) {
    int len = strlen(s);

    // Check for correct length and hyphen positions
    if (len != 19 || s[4] != '-' || s[9] != '-' || s[14] != '-') {
        printf("Invalid\n");
        return;
    }

    // Check for digits and invalid characters
    for (int i = 0; i < len; i++) {
    	if(isspace(s[i])) {
    		printf("Invalid\n");
    		return;
		}
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

    for(int i=0;i<n;i++) {
	
        char s[MAX_LENGTH];
        fgets(s, sizeof(s), stdin);

        // Remove newline character from fgets
        int len=strlen(s);
        if(len!=0 && s[len]=='\n') {
        	s[len]='\0';
		}

        check(s);
    }


    return 0;
}

