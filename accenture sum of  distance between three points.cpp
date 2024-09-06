#include <stdio.h>
#include <math.h>

int main() {
	float x1;float y1;
	printf("Enter x1 and y1: ");
	scanf("%f",&x1);
	scanf("%f",&y1);
	float x2;float y2;
	printf("Enter x2 and y2: ");
	scanf("%f",&x2);
	scanf("%f",&y2);
	float x3;float y3;
	printf("Enter x3 and y3: ");
	scanf("%f",&x3);
	scanf("%f",&y3);
	
	float dist1=(float) sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	float dist2=(float) sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	float dist3=(float) sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	float sum=dist1+dist2+dist3;
	printf("%f",sum);
	return 0;
	
	
	
}
