#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 20 //using 20 a maximum as file only goes to 13 max

// typedef struct
// {
//     char str[20];
//     int row, col;
//     int **arr;
// } data;

// int j = 0;
// int k = 0;

// int *get_Matrix()
// {
//     FILE *fp;
//     char *file = "./matrix_test.txt";
//     char c;
//     int count = 0;
//     int rows = 0;
//     int cols = 0;
//     int matrix[20][20];
//     int val;

//     fp = fopen(file, "r");
//     while (!feof(fp))
//     {
//         fscanf(fp, "%c", &c);
//         if (count != currentLine) //counts up to previous line
//         {
//             count++;
//         }
//         else
//         {
//             continue;
//         }
//         if (c == ',')
//         {
//             cols++;
//         }
//         if (c == '\n')
//         {
//             rows++;
//             currentLine++;
//         }
//     }
//     fclose(fp);
//     // matrix = malloc(rows * cols * sizeof(int));
//     fp = fopen(file, "r");
//     // for (int row = 0; row < rows; row++)
//     // {
//     //     for (int col = 0; col < cols; col++)
//     //     {
//     //         fscanf(fp, "%d%c", &val, &c);
//     //         matrix[(row * cols) + col] = val;
//     //     }
//     // }

//     for (int i = 0; i < rows; ++i)
//     {
//         for (int j = 0; j < cols; ++j)
//         {
//             fscanf(fp, "%d", &matrix[i][j]);
//             printf("what the fuck? %c \n ", matrix[i][j]);
//         }
//     }
//     // return matrix;
// }
// void multiplyMatrices(int * matrix1, int * matrix2, int result[][N], int cols, int rows)
// {
//     int i, j, k;

//     for (int i = 0; i < cols; i++)
//     {
//         for (int j = 0; j < rows; j++)
//         {
//             result[i][j] = 0.0;
//             for (int k = 0; k < N; k++)
//             {
//                 result[i][j] += matrix1[i][k] * matrix2[k][j];
//             }
//         }
//     }
//     // for (i = 0; i < N; i++)
//     // {
//     //     for (j = 0; j < N; j++)
//     //     {
//     //         result[i][j] = 0;
//     //         for (k = 0; k < N; k++)
//     //             result[i][j] += matrix1[i][k] * matrix2[k][j];
// }

int main(void)
{
    int result[20][20]; //used int for greater readability
    // get_Matrix();
    FILE *fp;
    int currentLine = 0;

    char *file = "./matrix_test.txt";
    char c;
    int count = 0;
    int rows = 0;
    int cols = 0;
    int matrix[20][20];
    int matrix2[20][20];
    int val;
    char line[256];
    char *split;
    int i = 0;

    fp = fopen(file, "r");

    if (!fp)
    {
        printf("nope");
    }
    while ((fgets(line, sizeof(line), fp)))
    {
        if (*line == '\n')
        {
            currentLine++;
            break;
        }
        currentLine++;
        split = strtok(line, ","); //splits the string by comma
        // printf("%s", split);
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
                matrix[currentLine - 1][i] = atoi(split); //sets matrix position to int of split token
                
                printf("%d\n", matrix[currentLine - 1][i]);
                i++;
                split = strtok(NULL, ",");
            }
        }
    }
    close(fp);
    // while (fgets(line, sizeof(line), fp))
    // {
    //     printf("%s", line);
    //     if (count != currentLine) //counts up to previous line
    //     {
    //         count++;
    //         printf("count: %d \n", count);
    //     }
    //     else
    //     {
    //         if (*line == ',')
    //         {
    //             cols++;
    //             printf("cols: %d \n", cols);
    //         }
    //         if (*line == '\n')
    //         {
    //             rows++;
    //             printf("rows: %d \n", rows);
    //             currentLine++;
    //         }
    //     }
    // }
    // for (int i = 0; i < rows; ++i)
    // {
    //     for (int j = 0; j < cols; ++j)
    //     {
    //         fscanf(fp, "%d", &matrix[i][j]);
    //         printf("what the fuck? %c \n ", matrix[i][j]);
    //     }
    // }
    // multiplyMatrices(get_Matrix(), get_Matrix(), result, cols, rows);

    //reading/displaying result
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         printf("%d ", result[i][j]);
    //     printf("\n");
    // }
    return 0;
}

/********************************************************unused code which may have use ******************************************************/
// get_Matrix_One(matrix);
// printf("*************");
// get_Matrix_Two(matrix2);
// float elements = sizeof(matrix)/sizeof(*matrix);
// for (i = 0; i < N; i++)

// for (int i = 0; i < M; i++)
// {
// for (int j = 0; j < N; j++)
// {
// A[i][j] = i + j + 1;
// B[j][i] = (i + 1) * (j + 1);
// }
// }
//
// for (int i = 0; i < M; i++)
// {
// for (int j = 0; j < M; j++)
// {
// C[i][j] = 0.0;
// for (int k = 0; k < N; k++)
// {
// C[i][j] += A[i][k] * B[k][j];
// }
// }
// }
//
// for (int i = 0; i < M; i++)
// {
// for (int j = 0; j < M; j++)
// {
// printf("%lf\t", C[i][j]);
// }
// printf("\n");
// }
