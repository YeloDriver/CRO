#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lireSudoku(FILE *fich, int sudoku[9][9])
{
  int i, j, res;
  int val;
  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++)
    {
      res = fscanf(fich, "%d", &val);
      if (res == EOF)
      {
        fprintf(stderr, "Fin de ficher atteinte: manque des coefficients\n");
        exit(-1);
      }
      sudoku[i][j] = val;
    }
  return (0);
}

int ecrireSudoku(FILE *fich, int sudoku[9][9])
{
  int i, j;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      fprintf(fich, "%d ", sudoku[i][j]);
    }
    fprintf(fich, "\n");
  }
  return (0);
}

int sudokuValide(int sudoku[9][9])
{
  int i, j, k;
  int val;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      val = sudoku[i][j];

      if (val == 0)
      {
        return (0);
      }

      for (k = 0; k < 9; k++)
      {
        if (i != k && sudoku[k][j] == val)
        {
          return (0);
        }
        if (j != k && sudoku[i][k] == val)
        {
          return (0);
        }
        if ((i/3)*3+k/3 != i && (j/3)*3+k%3 != j && sudoku[(i/3)*3+k/3][(j/3)*3+k%3] == val) //一个用除数，一个用余数，/代表除数，%代表余数
        {
          return (0);
        }
      }
    }
  }

  return (1);
}

int sudokuSimple(int sudoku[9][9]){
  int i, j, k;
  int M[9][9][9]={0};
  int val;
  int done;
  int count;
  int lastVal;

  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      val = sudoku[i][j];
      if (val != 0)
      {
        for (k = 0; k < 9; k++)
        {
          M[k][j][val - 1] = 1;
          M[i][k][val - 1] = 1;
          M[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3][val - 1] = 1;
        }
      }
    }
  }

  fprintf(stdout, "start simple solver\n");
  while (sudokuValide(sudoku) == 0)
  {
    done = 0;
    for (i = 0; i < 9; i++)
    {
      for (j = 0; j < 9; j++)
      {
        val = sudoku[i][j];
        count = 0;
        if (val == 0)
        {
          for (k = 0; k < 9; k++)
          {
            if (M[i][j][k] == 0)
            {
              count += 1;
              lastVal = k;
            }
          }
          if (count == 1)
          {
            done = 1;
            sudoku[i][j] = lastVal + 1;
            for (k = 0; k < 9; k++)
            {
              M[k][j][lastVal] = 1;
              M[i][k][lastVal] = 1;
              M[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3][lastVal] = 1;
            }
          }
        }
      }
    }
    if (done == 0)
    {
      printf("Sudoku isn't simple\n");
      return (0);
    }
  }
  printf("Sudoku is simple\n");
  ecrireSudoku(stdout, sudoku);
  return (1);
}