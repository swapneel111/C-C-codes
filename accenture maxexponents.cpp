#include <stdio.h>

int maxExponents (int a , int b) {
	int count;
	int maxExponent=0;
	int exponent=0;
	int maxCount=0;
	for(int i=a;i<=b;i++) {
		while(i%2==0 && i!=0) {
			exponent++;
			if(exponent>maxExponent) {
				maxExponent=exponent;
			}
			i=i/2;
			int count=i;
			if(count>maxCount) {
				maxCount=count;
			}
		}


	}
	return count;
}

int main ()
{
  int a, b;
  scanf ("%d %d", &a, &b);
  printf ("%d", maxExponents (a, b));
  return 0;
}
