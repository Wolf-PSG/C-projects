#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
int getMatrixDimensions(int *rows, int *cols, int *startingLine)
{
  printf("******************GETTING***************** \n");
  char *file = "./matrix_test.txt";
  FILE *fp;
  char line[256];
  char *split;
  int i = 0;
  int firstCheck = 0;
  int counter = 0;
  printf("startingLine from getting: %d", *startingLine);
  printf("count in getting: %d \n", counter);

  fp = fopen(file, "r");
  while (fgets(line, sizeof(line), fp))
  {
    if (counter != *startingLine) //counts up to previous line
    {
      counter += 1;
      printf("count: %d \n", counter);
    }
    else
    {
      if (firstCheck == 0)
      {
        printf("firstCheck %d \n", firstCheck);
        split = strtok(line, ",");
        while (split != NULL)
        {
          *cols += 1;
          printf("cols: %d \n", *cols);
          split = strtok(NULL, ",");
          firstCheck = 1;
        };
      }
      *rows += 1;
      printf("rows: %d \n", *rows);
      if (line[0] == '\n')
      {
        --*rows;
        break;
      }
    }
  }
  fclose(fp);
}

int addMatrixElements(float matrix[][20], int *rows, int *cols, int *startingLine)
{
  char *file = "./matrix_test.txt";
  FILE *fp;
  char line[256];
  char *split;
  int *i, *j;
  i = (int *)malloc(sizeof(int));
  j = (int *)malloc(sizeof(int));
  *i = 0;
  *j = 0;
  int counter = 0;
  int currentLine = 0;
  printf("startingLine: %d", *startingLine);
  fp = fopen(file, "r");
  printf("******************ADDING***************** \n");
  while ((fgets(line, sizeof(line), fp)))
  {

    if (counter != *startingLine)
    {
      ++counter;
    }
    else
    {
      split = strtok(line, ","); //splits the string by comma
      while (split != NULL)      // iterates over the split
      {
        if (*j == *cols)
        {
          *i += 1;
          *j = 0;
        }
        float a = atof(split);

        matrix[*i][*j] = a;
        printf("matrix 2: %f \n ", matrix[*i][*j]);
        *j += 1;
        split = strtok(NULL, ",");
      }
      if (line[0] == '\n')
      {
        *startingLine = *i + 1;
        break;
      }
    }
  }
  free(i);
  free(j);
  fclose(fp);
}

int multiplyMatrix(float matrix[][20], float matrix_2[][20], float final_matrix[][20], int *rows_1, int *cols_1, int *cols_2)
{
  for (int i = 0; i <= *rows_1; i++)
  {
    for (int j = 0; j < *cols_2; j++)
    {
      for (int k = 0; k < *cols_1; k++)
      {
        printf("Matrix output %f \n", matrix[i][k]);
        printf("Matrix_2 output %f \n", matrix_2[k][j]);
        final_matrix[i][j] += matrix[i][k] * matrix_2[k][j];
        printf("Matrix final output %f \n", final_matrix[i][j]);
      }
    }
  }
  return 0;
}

int main(void)
{
  int *rows_1, *cols_1, *rows_2, *cols_2, *startingLine;
  float(*matrix)[20] = malloc(1000 * sizeof(float));
  float(*matrix_2)[20] = malloc(1000 * sizeof(float));
  float(*final_matrix)[20] = malloc(1000 * sizeof(float));
  rows_1 = (int *)malloc(sizeof(int));
  rows_2 = (int *)malloc(sizeof(int));
  cols_1 = (int *)malloc(sizeof(int));
  cols_2 = (int *)malloc(sizeof(int));
  startingLine = (int *)malloc(sizeof(int));
  getMatrixDimensions(rows_1, cols_1, startingLine);
  addMatrixElements(matrix, rows_1, cols_1, startingLine);
  printf("startingLine in main: %d", *startingLine);
  getMatrixDimensions(rows_2, cols_2, startingLine);
  addMatrixElements(matrix_2, rows_2, cols_2, startingLine);
  multiplyMatrix(matrix, matrix_2, final_matrix, rows_1, cols_1, cols_2);
  free(matrix);
  free(matrix_2);
  for (int i = 1; i <= *rows_1; i++)
  {
    for (int j = 0; j < *cols_1; j++)
    {
      printf("results: %f \n ", final_matrix[i][j]);
    }
  }
  free(rows_1);
  free(cols_1);
  free(rows_2);
  free(cols_2);
  return 0;
}