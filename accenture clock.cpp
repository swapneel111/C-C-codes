#include <stdio.h>
#include <string.h>

void convertTime(char* time12) {
	int hour,minute,second;
	char period[3];
	
	sscanf(time12,"%02d:%02d:%02d%2s",&hour,&minute,&second,period);
	
	if(strcmp(period,"AM")==0 && hour==12) {
		hour=0;
	}
	if(strcmp(period,"PM")==0 && hour!=12) {
		hour+=12;
	}
	
	printf("%02d:%02d:%02d \n",hour,minute,second);
	
	
}

int main() {
    char time12[12];

    // Example Input 1
    strcpy(time12, "12:01:11PM");
    convertTime(time12);  // Output: 12:01:11

    // Example Input 2
    strcpy(time12, "12:01:11AM");
    convertTime(time12);  // Output: 00:01:11

    return 0;
}
