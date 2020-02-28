# include <stdio.h>
# define N 5

int produit_scalaire(int A[N], int B[N]){
	int res = 0;
	for (int i = 0; i < N; i++)
	{	
		res += A[i] * B[i];
	}
	return res;
}

int main() {
	int A[N] = {1,2,3,4,5};
	int B[N] = {1,2,3,4,5};

	printf("Produit scalaire: %d\n", produit_scalaire(A,B));
	return 0;
}