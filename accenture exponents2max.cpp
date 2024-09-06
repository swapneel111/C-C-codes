#include <stdio.h>

int maxExponents(int a, int b) {
    int maxExponent = 0;
    int maxNumber = 0;

    for (int i = a; i <= b; i++) {
        int exponent = 0;
        int num = i;

        while (num % 2 == 0 && num != 0) {
            exponent++;
            num = num / 2;
        }

        if (exponent > maxExponent) {
            maxExponent = exponent;
            maxNumber = i;
        }
    }

    return maxNumber;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int maxNumber = maxExponents(a, b);
    printf("%d\n", maxNumber);
    return 0;
}

