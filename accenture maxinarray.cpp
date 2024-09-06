#include <stdio.h>


void maxInArray(int arr[], int length) {
	int max=0;
	int index;
	for(int i=0;i<length;i++) {
		if(arr[i]>max) {
			index=i;
			max=arr[i];
		}
	}
	printf("The maximum element in the array is %d\n ",max);
	printf("The index of element in the array is %d\n ",index);

}


int main ()
{
  	int n;
  	scanf ("%d", &n);
  	int arr[n];
  	for (int i = 0; i < n; i++){
	  
		scanf ("%d", &arr[i]);}
		
  maxInArray (arr, n);
  return 0;
}
