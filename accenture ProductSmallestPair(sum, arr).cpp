#include<stdio.h>

int swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}

int productSmallestPair (int array[], int n, int sum)
{	
	int check;
	int result;
	if(n<2) {
		result= -1;
	}
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(array[i]>array[j]) {
				swap(&array[i],&array[j]);
			}
		}
	}
	
	check=array[0]+array[1];
	if(check<=sum) {
		result=array[0] * array[1];
	}
	else {
		result=0;
	}
	
	return result;
}


int main ()
{
  int n, sum, result, i;
  scanf ("%d", &sum);
  scanf ("%d", &n);
  int array[n];
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &array[i]);
    }
  result = productSmallestPair (array, n, sum);
  printf ("%d", result);
  return 0;
}

	
	
	
	
