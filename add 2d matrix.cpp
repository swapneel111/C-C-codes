#include <stdio.h>

int main() {
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    
    int arr1[r][c];
    int arr2[r][c];
    int result[r][c];
    
	
	printf("Enter elements of arr1: ");
    // Initialize the array with 0s
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d",&arr1[i][j]); // Explicitly setting each element to 0
        }
    }
    
    for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			printf("%d",arr1[i][j]);
		}
		printf("\n");
}
 
    printf("Enter elements of arr2: ");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        	printf("Enter elements of arr2");
            scanf("%d",&arr2[i][j]); 
        }
    }
    
    for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			printf("%d",arr2[i][j]);
		}
		printf("\n");
}

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j]=arr1[i][j] + arr2[i][j]  ;
        }
    }
    pri
    printf("The result is : ");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf( "%d",result[i][j]);
        }
    }
    printf("\n");
    
    return 0;
}

