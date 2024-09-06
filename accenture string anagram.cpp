#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char*a,char*b) {
	char temp=*a;
	*a=*b;
	*b=temp;
}

void sortString(char* str) {
	int len=strlen(str);
	for(int i=0;i<len-1;i++) {
		for(int j=i+1;j<len;j++) {
			if (str[i]>str[j]) {
				swap(&str[i],&str[j]);	
			}
		}
	}
	
}

int anagram(char* str1,char* str2) {
	int length1=strlen(str1);
	int length2=strlen(str2);
	
	if(length1!=length2) {
		printf("Cannot be anagram \n") ;
	}
	
	sortString(str1);
	sortString(str2);
	
	if(strcmp(str1,str2)==0) {
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
	char str1[]="listen";
	char str2[]="silent";
	printf("Are '%s' and '%s' anagrams? %s\n",str1,str2,anagram(str1,str2) ? "yes":"no");
	
	char str3[]="hello";
	char str4[]="world";
	printf("Are '%s' and '%s' anagrams? %s\n",str3,str4,anagram(str3,str4) ? "yes" : "no");
	
	return 0;
}
