#include <stdio.h>
#include <string.h>

// Function to print an array
void printArray(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void swap (char *a,char *b) {
	char temp= *a;
	*a = *b;
	*b= temp;
}

void permute(char arr[],int start,int end) {
	if(start==end) {
		printArray(arr,end+1);
	}
	else{
		for(int i=start;i<=end;i++){
			
			swap(&arr[start],&arr[i]);
			permute(arr,start+1,end);
			swap(&arr[i],&arr[start]);
	}
	
	arr[end+1]='\0';
}
}

int main() {
    // Array initialization3
    char arr[] = "CAT";
    int n = strlen(arr);

    // Call the permute function to generate all permutations
    printf("All permutations of the array are:\n");
    permute(arr, 0, n - 1);

    return 0;
}
