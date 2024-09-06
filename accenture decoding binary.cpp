#include <stdio.h>
#include <string.h>

void decodeMessage(int n, int k, char* s) {
    int decoded[n]={0};
    
    decoded[0] = s[0] - '0';
    
    int current_xor = decoded[0];

    for (int i = 1; i < n; i++) {
        if (i < k) {
            decoded[i] = (s[i] - '0') ^ current_xor;
        } else {
            current_xor ^= decoded[i - k];
            decoded[i] = (s[i] - '0') ^ current_xor;
        }
        current_xor ^= decoded[i];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", decoded[i]);
    }
    printf("\n");
}

int main() {
    int n, k;
    char s[200]; 
    
    
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    decodeMessage(n, k, s);
    
    return 0;
}

