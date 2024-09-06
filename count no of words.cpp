#include <stdio.h>
#include <string.h>
#include <ctype.h>

int numberWords(char* str,int n) {
	if(n==0) {
		return 0;
	}
	
	int wordCount=0;
	int inWord=0;
	
	for(int i=0;i<n;i++) {
		if(isspace(str[i]) || ispunct(str[i])) {
			inWord=0;
		}
		
		if(isalnum(str[i])) {
			if(inWord==0) {
				wordCount++;
				inWord=1;
			}
		}
	}
	
	return wordCount;
}

int main() {
	char str[]="I am a good boy.I am bad";
	int n=strlen(str);
	printf("Number of words: %d\n",numberWords(str,n));
	return 0;
	
}


