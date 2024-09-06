#include <stdio.h>

int numberOfCarries(int num1 , int num2) {
	int carry=0;
	int carryValue;
	while(num1!=0 && num2!=0) {
		
		int rem1=num1%10;
		int rem2=num2%10;
		int sum=rem1+rem2+carryValue;
		if(sum>9) {
			carry+=1;
			carryValue=1; 
		}
		else{
			carryValue=0;
		}
		num1=num1/10;
		num2=num2/10;
		
	}
	return carry;
}

int main ()
{
  int x, y, a;
  scanf ("%d", &x);
  scanf ("%d", &y);
  a = numberOfCarries (x, y);
  printf ("%d", a);
  return 0;
}
