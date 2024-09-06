#include <stdio.h>
#include <string.h>

int CheckPassword(char str[], int n) {
	if (n<4) {
		return 0;
	}
	
	
	if(str[0]-'0'<=0 && str[0]-'0'<=9) {
		return 0;
		
	}
	int cap=0;int num=0;
	
	for(int i=0;i<n;i++) {
		if(str[i]==' ' || str[i]=='/') {
			return 0;
		}
		else if(str[i]>='A' && str[i]<='Z') {
			cap++;
		}
		else if(str[i]-'0'>=0 && str[i]-'0'<=9) {
			num++;
		}
	}
	
	return (num>0 && cap>0) ? 1:0;
}

int main() {
	char str[100];
	fgets(str,sizeof(str),stdin);
	int len = strlen (str);
  if (str[len - 1] == '\n')
    {
      str[len - 1] = '\0';	// Remove the newline character
      len--;			// Decrement the length
    }
  int result = CheckPassword (str, len);
  printf ("%d\n", result);
  return 0;
}

		
