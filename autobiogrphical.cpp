#include <string.h>
#include <stdio.h>


int findAutoCount(char n[]) {
	int cntZero=0,cntOne=0,cntTwo=0,cntThree=0;
	int len=strlen(n);
	int hash[10]={0};
	int count=0;
	for(int i=0;i<len;i++) {
		n[i]=n[i]-'0';
		hash[n[i]]++;
	}
	
	for(int i=0;i<len;i++) {
		if (hash[i]==n[i]) {
			printf("The number is an autobiographical number");
		}
		else {
  			printf("Not autobiographical");
	  	}
	  	  
}	
}

int main ()
{
  char n[100];
  scanf ("%s",n);
  findAutoCount(n);
  return 0;
}
