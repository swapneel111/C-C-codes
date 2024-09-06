#include <stdio.h>
#include <string.h>

int check_palindrome(const char str[],int left,int right) {
	if (left>=right)
	 	return 1;
	else if (str[left]==str[right])
		return check_palindrome(str,left+1,right-1);
	else
		return -1;
		
} 

int find_palindrome(char* str) {
	int len=strlen(str);
	
	for(int i=0;i<len;i++) {
		for(int j=i+1;j<=len;j++) {
			if(check_palindrome(str,i,j-1)) {
				printf("%s\n",j-1,str[i]);
			}
		}
	}
	
	return 0;
	
}

int main() {
	char str[]="abaaba";
	find_palindrome(str);
	printf("%s",find_palindrome(str));
	return 0;
}
