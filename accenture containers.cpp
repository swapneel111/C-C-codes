#include <stdio.h>

void swap(int*a,int*b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

int smallestContainer(int weights[],int n) {

	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(weights[i]>weights[j]){
				swap(&weights[i],&weights[j]);
		}
	}
}
	int count=1;
	int smallest=weights[0];
	
	for(int i=0;i<n;i++) {
		if(weights[i]-smallest<=4 && weights[i]-smallest>=0 ){
			continue;
		}
		else{
			smallest=weights[i];
			count+=1;
		}
	}
	
	return count;	
}

int main() {
	int n;
	scanf("%d",&n);
	int weights[n];
	printf("Enter the weights: ");
	for(int i=0;i<n;i++) {
		scanf("%d",&weights[i]);
	}
	int count=smallestContainer(weights,n);
	printf("%d",count);
	return 0;	
}
