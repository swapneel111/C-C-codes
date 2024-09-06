#include <stdio.h>

int calculate(int r,int unit,int arr[],int n) {
	if(n==0) {
		return -1;
	}
	int totalFood=r*unit;
	int foodTillNow=0;
	int count=0;
	
	for (int house=0;house<n;house++) {
		foodTillNow+=arr[house];
		if(foodTillNow>=totalFood) {
			count=house+1;
			break;
			
		}
	}
	if(totalFood>foodTillNow) {
			return 0;
		}
	return count;
}

int main() {
	int r,unit,n;
	printf("The value of r: ");
	scanf("%d",&r);
	printf("The value of unit: ");
	scanf("%d",&unit);
	printf("The value of n: ");
  	scanf ("%d", &n);
  	int arr[n];
  	printf("Enter the array elements: \n");
  	for (int i = 0; i < n; ++i)
    {
      scanf ("%d", &arr[i]);
    }
	int count=calculate(r,unit,arr,n);
	printf("%d",count);
	return 0;
}
