#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int *minSubarraySum(int arr[],int n,int k,int*ansStart,int* ansEnd) {
	int left=0;
	int right=k;
	int sum=0;
	int minSum=INT_MAX;
	
	
	for(int i=left;i<=right;i++) {
		while(right<n && left<right) {
			for(int i=left;i<=right;i++) {
				sum+=arr[i];
			}
			if(sum<minSum) {
				minSum=sum;
				*ansStart=left;
				*ansEnd=right;
				
}
			left++;
			right++;
		}
	}
	
	int *result=(int*)malloc(n*sizeof(int));
	for(int i=ansStart;i<=ansEnd;i++) {
		printf("%d",result[i]);
	}
	printf("\n");
	
	return res;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int* result = minSubarraySum(arr, n, k);

    for (int i = 0; i < k; ++i)
        printf("%d ", result[i]);

    free(arr);
    free(result);
    
    return 0;
}
