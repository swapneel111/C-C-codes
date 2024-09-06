#include <stdio.h>

int isPalindrome(int a,int b) {
	int rem;

	for(int i=a;i<=b;i++) {
		int reverse=0;
		int num=i;
		int original=num;
		while(num!=0) {
			rem=num%10;
			reverse=reverse*10+rem;
			num=num/10;
		}
		if(reverse==original) {
			printf("%d \n",original);
		}
	
	}
	
}

int main() {
	int a;
	scanf("%d",&a);
	int b;
	scanf("%d",&b);
	int rem;int reverse;
	
	isPalindrome(a,b);
	return 0;
	
	
}
