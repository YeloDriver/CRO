#include <stdio.h>

int factorielle(int n){
	int  i, fact = 1;
	for (i = 1; i<=n; i++)
		fact *= i;
	return fact;
}

int main(){
	printf("10! = %d\n", factorielle(10));
	return(0);
}