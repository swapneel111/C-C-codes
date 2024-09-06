#include <stdio.h>
#include <string.h>

void caesarCipher(char *s, int k) {
	
	int n=strlen(s);
	
	k=k%26;
	
	for(int i=0;i<n;i++) {
		if (s[i]>='a' && s[i]<='z') {
			s[i]=(s[i]-'a'+k)%26 +'a';
		}
		else if(s[i]>='A' && s[i]<='Z') {
			s[i]=(s[i]-'A'+k)%26 +'A';
		}
	}
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n+1];
    scanf("%s", s);//scanf automatically null terminates string after scanning

    int k;
    scanf("%d", &k);

    caesarCipher(s, k);

    printf("%s\n", s);

    return 0;
}
