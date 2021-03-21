#include <stdio.h>

void main(int argc, char *argv[]){

  FILE *fpSrc, *fpDest;
  char c;

  fpSrc = fopen(argv[1], "r");
  fpDest = fopen(argv[2], "w");

  while (!feof(fpSrc)){
    c = fgetc(fpSrc);
    fputc(c, fpDest);
  }
  fclose(fpSrc);
  fclose(fpDest);
}
