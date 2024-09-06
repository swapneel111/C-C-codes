#include <stdio.h>

int isPalindrome(int a,int b) {
	int rem;
	int reverse=0;
	for(int i=a;i<=b;i++) {
		int num=i;
		while(num!=0) {
			rem=num%10;
			reverse=reverse*10+rem;
			num=num/10;
		}
		if(reverse==num) {
			printf("%d",&num);
		}
	
	}
	
}

int main() {
	int a;
	scanf("%d",&a);
	int b;
	scanf("%d",&b);
	int rem;int num;
	
	isPalindrome(a,b);
	return 0;
	
	
}
