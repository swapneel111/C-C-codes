#include <stdio.h>
#include <string.h>

void binaryOperation(char* bin1,char* bin2,char* result,char operation[]) {
	int length1=strlen(bin1);
	int length2=strlen(bin2);
	
	if(length1!=length2) {
		printf("The lengths of both the strings shoule be same \n");		
	}
	
	for(int i=0;i<length1;i++) {
		int bit1=bin1[i]-'0';
		int bit2=bin2[i]-'0';
		int res;
		
		if (operation[0] == 'A' && operation[1] == 'N' && operation[2] == 'D') {
			res=bit1&bit2;	
		}
		else if (operation[0] == 'O' && operation[1] == 'R' && operation[2] == '\0') {
			res=bit1|bit2;
		}
		if(operation[0] == 'X' && operation[1] == 'O' && operation[3] == 'R') {
			res=bit1^bit2;
		}
		else {
            printf("Error: Invalid operation. Use AND, OR, or XOR.\n");
        }
        
        result[i]=res+'0';

		
		
	}
	result[length1]=='\0';
	
	
}

int main() {
	char bin1[]="1101";
	char bin2[]="1011";
	char result[5];
	char operation[] = "AND";

    binaryOperation(bin1, bin2, result, operation);
    printf("Result of %s operation: %s\n", operation, result);

    return 0;
}
