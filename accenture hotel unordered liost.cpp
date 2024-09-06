#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUMBERS 1000

int main() {
    int k;
    printf("Enter the value of K: ");
    scanf("%d", &k);

    int room_numbers[MAX_ROOM_NUMBERS];
    int frequency[MAX_ROOM_NUMBERS] = {0}; // Initialize frequency array to 0
    int n;

    printf("Enter the number of room numbers: ");
    scanf("%d", &n);

    if (n > MAX_ROOM_NUMBERS) {
        printf("Error: Number of room numbers exceeds the maximum limit.\n");
        return 1;
    }

    printf("Enter the room numbers: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &room_numbers[i]); // Use & to store input correctly
    }

    for (int i = 0; i < n; i++) {
        frequency[room_numbers[i]]++;
    }

    // Find the room number with frequency 1
    for (int i = 0; i < n; i++) {
        if (frequency[room_numbers[i]] == 1) {
            printf("The Group Leader's room number is: %d\n", room_numbers[i]);
            break;
        }
    }

    return 0;
}


