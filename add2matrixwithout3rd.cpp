#include <stdio.h>

int main() {
	int matrix1[2][2]={{1,2},{2,3}};
	int matrix2[2][2]={{2,3},{3,5}};
	
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			matrix1[i][j]+=matrix2[i][j];
		}
	}
	
	printf("The final matrix is: \n");
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			printf("%d",matrix1[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
