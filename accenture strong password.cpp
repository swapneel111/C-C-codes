#include <stdio.h>
#include <string.h>


int main() {
	int n;
	scanf("%d",&n);
	char password[101];
	scanf("%d",password);
	
	int hasDigit=0;
	int hasUpper=0;
	int hasLower=0;
	char special[]="!@#$%^&*()-+";
	int hasSpecial=0;
	
	for(int i=0;i<n;i++) {
		if(password[i]>='A' && password[i]<='Z') {
			hasUpper=1;
		}
		if(password[i]>='a' && password[i]<='z') {
			hasLower=1;
		}
		if(password[i]>='0' && password[i]<='9') {
			hasDigit=1;
		}
		else{
			for(int j=0;j<sizeof(special);j++) {
				if(password[i]==special[j]) {
					hasSpecial=1;	
					break;
				}	
			}
		}
		
		int missingTypes=0;
		if(!hasUpper){
			missingTypes++;
		}
		if(!hasLower) {
			missingTypes++;
		}
		if(!hasDigit) {
			missingTypes++;
		}
		if(!hasSpecial){
			missingTypes++;
		}
		
		int charactersToAdd=missingTypes;
		if(n+charactersToAdd<6) {
			charactersToAdd=6-n;
		}
		printf("%d\n", charactersToAdd);
    
    return 0;
}
	}
	
	
	
