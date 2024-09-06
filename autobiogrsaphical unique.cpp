#include <stdio.h>
#include <string.h>

int findAutoCount(char n[]) {
    int len = strlen(n);
    int hash[10] = {0};
    int count = 0;
    int num[len];

    // Convert characters to integers and store them in num array
    for (int i = 0; i < len; i++) {
        num[i] = n[i] - '0';
        hash[num[i]]++;
    }

    // Check if the number is autobiographical
    for (int i = 0; i < len; i++) {
        if (hash[i] != num[i]) {
            return 0;
        }
    }

    // Count distinct numbers
    for (int i = 0; i < 10; i++) {
        if (hash[i] > 0) {
            count++;
        }
    }

    printf("The number is an autobiographical number\n");
    return count;
}

int main() {
    char n[100];
    scanf("%s", n);
    int count = findAutoCount(n);
    if (count > 0) {
        printf("The count is %d\n", count);
    } else {
        printf("Not autobiographical\n");
    }
    return 0;
}

