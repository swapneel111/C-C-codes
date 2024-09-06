#include <stdio.h>

int swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}

int LargeSmallSum (int arr[], int length) {
	int sum;
	if (length <= 3)
    {
      return 0;
    }
	int evenPos[100];
	int oddPos[100];
	int evenCount=0;
	int oddCount=0;
	for (int i=0;i<length;i++) {
		if(i%2==0) {
			evenPos[evenCount++]=arr[i];
		}
		else{
			oddPos[oddCount++]=arr[i];
		}
	}
	
	for(int i=0;i<evenCount-1;i++) {
		for(int j=i+1;j<evenCount;j++) {
			if(evenPos[i]>evenPos[j]) {
				swap(&evenPos[i],&evenPos[j]);
			}
		}
	}
	for(int i=0;i<oddCount-1;i++) {
		for(int j=i+1;j<oddCount;j++) {
			if(oddPos[i]>oddPos[j]) {
				swap(&oddPos[i],&oddPos[j]);
			}
		}
	}
	
	sum=oddPos[1]+evenPos[evenCount-2];
	return sum;
	
}

int main ()
{
  int arr[] = {3,2,1,7,5,4};
  int length = sizeof (arr) / sizeof (arr[0]);
  
  int sum=LargeSmallSum(arr,length);
  printf("%d",sum);
  return 0;
}

