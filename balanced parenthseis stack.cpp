#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MISMATCHES 100

struct Pair {
    char c1;
    char c2;
};

bool satisfy_condition(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Check if both strings have the same length
    if (len1 != len2) {
        return false;
    }

    struct Pair mismatches[MAX_MISMATCHES];
    int mismatch_count = 0;

    // Record mismatches
    for (int i = 0; i < len1; ++i) {
        if (s1[i] != s2[i]) {
            if (mismatch_count >= MAX_MISMATCHES) {
                return false; // Too many mismatches
            }
            mismatches[mismatch_count].c1 = s1[i];
            mismatches[mismatch_count].c2 = s2[i];
            ++mismatch_count;
        }
    }

    // Validate mismatches
    for (int i = 0; i < mismatch_count; ++i) {
        bool found_pair = false;
        for (int j = 0; j < mismatch_count; ++j) {
            if (i != j && mismatches[i].c1 == mismatches[j].c2 && mismatches[i].c2 == mismatches[j].c1) {
                found_pair = true;
                break;
            }
        }
        if (!found_pair) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test cases
    printf("%s\n", satisfy_condition("hello", "ehllo") ? "True" : "False");
    printf("%s\n", satisfy_condition("heleo", "eelho") ? "True" : "False");

    return 0;
}

