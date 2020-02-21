#include <stdio.h>

int main(){
	int nb;
	printf("Entrez un entier i = ");
	scanf("%d", &nb);
	for(int i=0; i<nb+1;i++){
		printf("%d au carré donne %d\n",i,i*i);
	}
	return(0);
}