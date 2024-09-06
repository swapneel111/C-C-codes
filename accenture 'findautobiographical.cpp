#include <string.h>
#include <stdio.h>


int findAutoCount(char n[]) {
	int cntZero=0,cntOne=0,cntTwo=0,cntThree=0;
	int len=strlen(n);
	for(int i=0;i<len;i++) {
		n[i]=n[i]-'0';
		if(n[i]==0) {
			cntZero++;
		}
		if(n[i]==1) {
			cntOne++;
		}
		else if(n[i]==2) {
			cntTwo++;
		}
		else if(n[i]==3) {
			cntThree++;
		}
	}
	
	if (n[0]==cntZero && n[1]==cntOne && n[2]==cntTwo && n[3] == cntThree) {
		printf("The number is an autobiographical number");
	}
  	else{
  		printf("Not autobiographical");
	  }
	
	
}

int main ()
{
  char n[100];
  scanf ("%s", n);
  findAutoCount(n);
  return 0;
}
