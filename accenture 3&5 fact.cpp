#include <stdio.h>

int calculate(int m, int n) {
	int sum=0;
	for(int i=m;i<=n;i++) {
		int num=i;
		if((num%3==0) && (num%5==0)) {
			sum+=num;
		}
	}
	return sum;
}

int main ()
{
    int m, n, result;
    printf ("Enter the value of m : ");
    scanf ("%d", &m);
    printf ("Enter the value of n : ");
    scanf ("%d", &n);
    int sum = calculate(m, n);
    printf ("%d",sum);
    return 0;
}
