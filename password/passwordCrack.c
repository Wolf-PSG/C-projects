#include <stdio.h>
// #include <omp.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 20 //using 20 a maximum as file only goes to 13 max

FILE *fp;
char *file = "./1811952-matrices.txt";
int currentLine = 0;
char delim[] = ",";
int i = 0;
int j = 0;

float (*get_Matrix_One(void))[N]
{
    char *split;
    char line[256];
    float(*matrix)[20] = malloc(1000 * sizeof(float));
    char *value;
    fp = fopen(file, "r");

    while ((fgets(line, sizeof(line), fp)))
    {
        if (*line == '\n')
        {
            currentLine++;
            break;
        }
        currentLine++;
        split = strtok(line, ","); //splits the string by comma
        while (split != NULL)      // iterates over the split
        {
            if (currentLine == 1) //skips size of matrix line
            {
                break;
            }
            else
            {
                // printf("currentLine: %d\n", currentLine);
                // printf("i: %d\n", i);
                matrix[currentLine][i] = atoi(split); //sets matrix position to int of split token
                // printf("%f\n", matrix[currentLine][i]);
                i++;
                split = strtok(NULL, ",");
            }
        }
    }
    fclose(fp);
    return matrix;
}
// get matrix two
int main(void)
{
    int result[20][20]; //used int for greater readability
    multiplyMatrices(get_Matrix_One(), get_Matrix_Two(), result);
    //reading/displaying result
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    return 0;
}