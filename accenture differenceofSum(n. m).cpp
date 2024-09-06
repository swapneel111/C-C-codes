#include <stdio.h>

int differenceofSum(int n,int m) {
	int divSum=0;
	int notDiv=0;
	int result;
	for(int i=1;i<=m;i++) {
		if(i%n==0) {
			divSum+=i;
		}
		else{
			notDiv+=i;
		}
		
	}
	if(notDiv>divSum) {
		result=notDiv-divSum;
}
	else{
		result=notDiv-divSum;
	}
	return result;
}

int main() {
	int n=4;
	int m=20;
	int result=differenceofSum(n,m);
	printf("%d",result);
	return 0;
}
