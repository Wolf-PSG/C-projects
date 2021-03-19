#include <stdio.h>
#include <stdlib.h>



int main()
{
  int currentLine = 0;
  int rows = 0;
  int cols = 0;
  char c;
  FILE *f = fopen("matrix_test.txt", "r");
  if (!f)
  {
    fprintf(stderr, "Error: Unable to open input file.\n");
    exit(EXIT_FAILURE);
  }
  while (!feof(f))
  {
    fscanf(f, "%c", &c);
    if (c == ',')
    {
      cols++;
      printf("Col: %d", cols);
    }
    else if (c == '\n')
    {
      rows++;
      printf("row: %d", rows);
    }
    else
    {
      printf("empty");
    }
  }
}