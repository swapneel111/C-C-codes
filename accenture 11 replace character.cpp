#include <stdio.h>
#include <string.h>

void replaceCharacter(char str[], int n, char ch1, char ch2) {
    for (int i = 0; i < n; i++) {
        if (str[i] == ch1) {
            str[i] = ch2;
        } else if (str[i] == ch2) {
            str[i] = ch1;
        }
    }
    printf("%s\n", str);
}

int main() {
    char a[100];
    char b, c;
    scanf("%s", &a);
    scanf(" %c", &b);  // Use " %c" to consume any whitespace before reading the character
    scanf(" %c", &c);  // Same as above

    int len = strlen(a);
    replaceCharacter(a, len, b, c);

    return 0;
}

