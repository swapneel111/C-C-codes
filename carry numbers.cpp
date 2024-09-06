#include<stdio.h>

int numberOfCarries(int num1 , int num2) {
	int carryCount=0;
	int carry=0;
	
	while (num1!=0 && num2!=0) {
		int rem1=num1%10;
		int rem2=num2%10;
		int sum=rem1+rem2+carry;
		if(sum>9) {
			carryCount+=1;
			carry=1;
			
		}else{
			carry=0;
		}
		num1=num1/10;
		num2=num2/10;
		
	}
	return carryCount;
}

int main() {
	int num1;
	int num2;
	scanf("%d",&num1);
	scanf("%d",&num2);
	
	int carryCount=numberOfCarries(num1,num2);
	printf("%d",carryCount);
	return 0;	
}
