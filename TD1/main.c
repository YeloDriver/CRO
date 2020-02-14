#include <stdio.h>
#include "hello.h"

int main(){
	int erreur1, erreur2;

	erreur1 = hello();
	erreur2 = goodbye();

	if(erreur1!=0 && erreur2!=0)
		printf("Erreur in hello\n");

	return(0);
}