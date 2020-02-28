#include <stdio.h>
#include "matrice.h"
#include "matProd.h"

int matProd(int A[N][N], int B[N][N], int C[N][N])
{ 
  int temp = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        temp += A[i][k] * B[k][j];
      }
      C[i][j] = temp;
      temp = 0;
    }
  }
  return 0;
}
