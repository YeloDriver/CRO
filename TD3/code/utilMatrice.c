#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utilMatrice.h"         
     
int lireMatrice(FILE *fich,int mat[N][N])
{int i,j,res;
 int val; 
 for (i=0; i<N; i++) 
   for (j=0; j<N; j++) 
     {
       res=fscanf(fich, "%d",&val);
       if (res==EOF)
         {
           fprintf(stderr,"Fin de ficher atteinte: manque des coefficients\n");
           exit(-1);
         }
       mat[i][j]=val;
     }
 return(0);
}

int ecrireMatrice(FILE *fich,int mat[N][N])
{int i,j;
 for (i=0; i<N; i++) 
   {
     for (j=0; j<N; j++) 
       {
         fprintf(fich, "%d ",mat[i][j]);
       }
     fprintf(fich, "\n");
   }
 return(0);
}

bool matEqualQ(int A[N][N], int B[N][N]){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(A[i][j]!=B[i][j])
      {
        return false;
      }
    }
  }
  return true;
}