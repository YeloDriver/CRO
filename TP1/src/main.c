#include <stdio.h>

#include "pile.h"
#include "hanoi.h"

int main(int argc,char **argv)	
{
  int N;
  printf("Entrez le taille de la pile: ");
  scanf("%d", &N);

  PILE src = InitPile();
  PILE inter = InitPile();
  PILE dest = InitPile();
  int val, i;
  for (i = N; i > 0; i--)
  {
    val = i;
    src = Empiler(src, val);
  }

  printf("-----BEFORE-----\n");
  printf("Source: ");
  afficherPile(src);
  printf("\n");
  printf("INTER: ");
  afficherPile(inter);
  printf("\n");
  printf("Destination: ");
  afficherPile(dest);
  printf("\n");

  hanoi(&src, &inter, &dest, N);

  printf("-----AFTER-----\n");
  printf("Source: ");
  afficherPile(src);
  printf("\n");
  printf("INTER: ");
  afficherPile(inter);
  printf("\n");
  printf("Destination: ");
  afficherPile(dest);
  printf("\n");

  return 0;
}



