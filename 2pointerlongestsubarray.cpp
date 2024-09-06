#include <stdio.h>
#include <stdlib.h>

int getLongestSubarray(int a[], int n, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }

        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main() {
    int a[] = {2, 3, 5, 1, 9};
    int n = sizeof(a) / sizeof(a[0]);
    long long k = 10;

    int len = getLongestSubarray(a, n, k);
    printf("The length of the longest subarray is: %d\n", len);

    return 0;
}

