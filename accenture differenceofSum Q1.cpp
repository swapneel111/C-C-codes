#include <stdio.h>

int differenceofSum(int n,int m) {
	int nonDiv=0;
	int divSum=0;
	int diff;
	
	for(int i=1;i<=m;i++) {
		if (i%n==0) {
			divSum+=i;
		}else{
			nonDiv+=i;
		}
	}
	if(nonDiv>divSum) {
		diff=nonDiv=divSum;
	}
	else{
		diff=divSum-nonDiv;
	}
	return diff;
}

int main()
{
    int n, m;
    int diff;
    
    scanf("%d", &n);
    scanf("%d", &m);
    diff = differenceofSum(n,m);
    
    printf("%d",diff);
    return 0;
}
