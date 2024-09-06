#define MAX-SIZE 100;

int knows(a,b,matrix[MAX_SIZE][MAX-SIZE]) {

	return matrix[a][b]; //if matrix[a][b] is 1 it will return 1 or if 0 will return 0
}

int candi(int n,int matrix[][]) {
	int candidate=0;
	
	for(int i=0;i<n;i++) {
		if(knows(candidate,i,matrix)) {
			candidate=i;
		}
	}
}


	for(int j=0;j<n;j++) {
	
		if(j!= candidate && (knows(candidate,j,mat))  || (!knows(j,candidate,,mat))) {
			return -1;
		}
		}//this checks if a person j who is not same as candidate=i knows a person j or if a person j does not know candidate if any is true it basically means that i is not the candidate
		
		return candidate;
		
	}
