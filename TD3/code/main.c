#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrice.h"
#include "utilMatrice.h"
#include "matProd.h"
	 
int  main(int argc,char *argv[])
{
  FILE *fichA, *fichB, *ficheTest;
  char nomFichA[15]="matriceA.txt";
  char nomFichB[15]="matriceB.txt";
  char nomFichTest[15]="matriceAxB.txt";


  int A[N][N], B[N][N], C[N][N], test[N][N];
  int err;
  
  fichA=fopen(nomFichA,"r");
  if (!fichA)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichA);
      exit(-1);
    }

  fichB=fopen(nomFichB,"r");
  if (!fichB)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichB);
      exit(-1);
    }

  ficheTest=fopen(nomFichTest,"r");
  if (!ficheTest)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichTest);
      exit(-1);
    }  
  
  err=lireMatrice(fichA,A);
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichA);
      exit(-1);
    }

  err=lireMatrice(fichB,B); 
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichB);
      exit(-1);
    }
  
  err=lireMatrice(ficheTest,test);
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichTest);
      exit(-1);
    }

 fprintf(stdout," Matrice lues: \n");
 fprintf(stdout," A: \n");
 ecrireMatrice(stdout,A);

 fprintf(stdout," B: \n");
 ecrireMatrice(stdout,B);

 matProd(A,B,C);

 fprintf(stdout," resultat du produit C=AB (corrigé): \n");
 ecrireMatrice(stdout,C);
 
 fprintf(stdout," resultat de l'égalité entre A et B: \n");
 fprintf(stdout, "%s\n", matEqualQ(C,test) ? "true" : "false");

   return(0);
}
