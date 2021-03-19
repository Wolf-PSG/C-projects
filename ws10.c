#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct targs {
  int tid;
  int trow;
  int tcol;
  int rows;
  int cols;
  int *A;
  int *B;
  int *C;
  int aCols;
} args_t;

void readmatrix(char *filename, args_t *pArgs)
{
  FILE *fp;
  char c;
  int rows =0;
  int cols = 0;
  int *A;
  int val;

  fp = fopen(filename,"r");
  while(!feof(fp)){
    fscanf(fp,"%c",&c);
    if (c == ','){
      cols++;
    }
    if(c == '\n'){
      rows++;
    }
  }
  fclose(fp);
  rows--;
  cols = cols/rows;
  cols++;
  pArgs->rows = rows;
  pArgs->cols = cols;
  A = malloc(rows * cols * sizeof(int));
  pArgs->A = A;
  fp = fopen(filename,"r");
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      fscanf(fp, "%d%c", &val, &c);
      A[(row*cols)+col] = val;
    }
  }
}

void * matrixmul(void *p)
{
  int rows, cols;
  args_t *pArgs = p;
  rows = pArgs->rows;
  cols = pArgs->cols;
  int c = 0;
  for(int i = 0; i < pArgs->aCols; i++){
    int a = pArgs->A[(pArgs->trow * pArgs->cols)+ i];
    int b = pArgs->B[(i*pArgs->cols)+ pArgs->tcol];
    c = c + (a * b);
  }
  pArgs->C[(pArgs->trow * pArgs->cols) + pArgs->tcol] = c;
}

void main()
{
  args_t args1, args2, args3, args4;
  args_t *argsC1, *argsC2;
  int * C;
  int rows, cols;
  pthread_t *tid;
  
  readmatrix("Matrix1.txt",&args1);
  readmatrix("Matrix2.txt",&args2);
  readmatrix("Matrix3.txt",&args3);
  readmatrix("Matrix4.txt",&args4);

  rows = args1.rows;
  cols = args2.cols;
  C = malloc(rows*cols * sizeof(int));
  argsC1 = malloc(rows * cols * sizeof(args_t));
  tid = malloc(rows * cols * sizeof(pthread_t));
  for(int row =0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      argsC1[(row * cols) + col].rows = rows;
      argsC1[(row * cols) + col].cols = cols;
      argsC1[(row * cols) + col].trow = row;
      argsC1[(row * cols) + col].tcol = col;
      argsC1[(row * cols) + col].tid = (row * cols) + col;
      argsC1[(row * cols) + col].A = args1.A;
      argsC1[(row * cols) + col].B = args2.A;//Correct!
      argsC1[(row * cols) + col].C = C;
      argsC1[(row * cols) + col].aCols = args1.cols;
      pthread_create(&tid[(row * cols) + col],
        NULL,matrixmul,&argsC1[(row * cols) + col]);
    }
  }
  for(int row =0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      pthread_join(tid[(row * cols) + col],NULL);
      printf("C[%d][%d] = %d  ",row,col,
        argsC1[(row * cols) + col].C[(row * cols) + col]);
    }
    printf("\n");
  }

  /* Need to free the matrices when you are done */  
}
  