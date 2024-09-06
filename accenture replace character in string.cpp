#include <stdio.h>
#include <string.h>

void calculate(char* str,const char ch1,const char ch2,char* result) {
	int n=strlen(str);
	
	for(int i=0;i<n;i++) {
		if(str[i]==ch1) { 
			result[i]=ch2;
		}
		//else if(str[i]==ch2) {
		//	result[i]=ch1;
		//}
		else{
			result[i]=str[i];
	}
}

	result[n]='\0';
	
}

int main() {
	char str[]="banana";
	int n=strlen(str);
	char ch1='a';
	char ch2='b';
	char result[n+1];
	calculate(str,ch1,ch2,result);
	printf("Result of operation: %s\n",result);
	
	
}
