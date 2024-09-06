#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char*MoveHyphen(char str[],int n) {
	char* temp=(char*)malloc(n+1 * sizeof(char));
	int hyphen=0;
	for(int i=0;i<n;i++) {
		if(str[i]=='-') {
			temp[hyphen++]=str[i];
		}
		
	}
	for(int i=0,j=hyphen;i<n,j<n;i++) {
		if(str[i]!='-') {
			temp[j++]=str[i];
	}
	temp[n]='\0';
	
}
return temp;
}

int main ()
{
  char str[100];
  scanf ("%s",str);
  int n = strlen (str);
  char *temp = MoveHyphen (str, n);
  printf ("%s\n", temp);
  free(temp);
  return 0;

}
