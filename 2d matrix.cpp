#include <stdio.h>

int main() {
	int r,c;
	printf("Enter number of students: ");
	scanf("%d",&r);
	printf("Enter number of subjects: ");
	scanf("%d",&c);
	int arr[r][c]={0};
	printf("%d",arr[r][c]);
	//for(int i=0;i<r;i++) {
		//for(int j=0;j<c;j++) {
		//	scanf("%d",&arr[i][j]);
		//}
//	}
//	for(int i=0;i<r;i++) {
//		for(int j=0;j<c;j++) {
//			printf("%d",arr[i][j]);
//		}
//		printf("\n");
//	}
	return 0;
}
