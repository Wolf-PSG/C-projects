#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct 

void readmatrix(char *filename, args_t *pArgs)
{
    FILE *fp;
    char c;
    int rows = 0;
    int cols = 0;
    int *A;
    int val;

    fp = fopen(filename, "r");
    while (!feof(fp))
    {
        fscanf(fp, "%c", &c);
        if (c == ',')
        {
            cols++;
        }
        if (c == '\n')
        {
            rows++;
        }
    }
    fclose(fp);
    rows--;
    cols = cols / rows;
    cols++;
    pArgs->rows = rows;
    pArgs->cols = cols;
    A = malloc(rows * cols * sizeof(int));
    pArgs->A = A;
    fp = fopen(filename, "r");
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            fscanf(fp, "%d%c", &val, &c);
            A[(row * cols) + col] = val;
        }
    }
}