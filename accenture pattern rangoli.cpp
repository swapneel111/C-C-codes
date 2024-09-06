#include <stdio.h>
#include <string.h>

void print_rangoli(int size) {
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char lines[size][100];  // Assuming max length of each line won't exceed 100 chars
    int width;

    // Generate the lines
    for (int row = 0; row < size; row++) {
        char to_print[100] = "";
        for (int i = row; i < size; i++) {
            char temp[3] = {alpha[i], '\0'};
            strcat(to_print, temp);
            if (i != size - 1) strcat(to_print, "-");
        }

        // Reverse to_print and concatenate with the rest
        char reverse_part[100] = "";
        int len = strlen(to_print);
        for (int j = len - 1; j > 0; j--) {
            char temp[2] = {to_print[j], '\0'};
            strcat(reverse_part, temp);
        }

        strcpy(lines[row], reverse_part);
        strcat(lines[row], to_print);
    }

    width = strlen(lines[0]);

    // Print the upper half
    for (int row = size - 1; row > 0; row--) {
        int pad = (width - strlen(lines[row])) / 2;
        for (int i = 0; i < pad; i++) {
            printf("-");
        }
        printf("%s", lines[row]);
        for (int i = 0; i < pad; i++) {
            printf("-");
        }
        printf("\n");
    }

    // Print the lower half including the center
    for (int row = 0; row < size; row++) {
        int pad = (width - strlen(lines[row])) / 2;
        for (int i = 0; i < pad; i++) {
            printf("-");
        }
        printf("%s", lines[row]);
        for (int i = 0; i < pad; i++) {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of Rangoli: ");
    scanf("%d", &size);

    print_rangoli(size);

    return 0;
}

