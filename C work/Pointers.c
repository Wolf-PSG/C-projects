#include <stdio.h>

int main() {
  int a;
  a = 10;
  int b = 20;
  int c;
  int * Aptr;
  int *Bptr;
  int *Cptr;
  Cptr = &c;
  Aptr = &a;
  Bptr = &b;
  c = ((*Aptr + *Bptr));
  printf("a = %d\n", a);
  printf("%p\n", (void *) &a);

  printf("*Aptr = %d\n", *Aptr);
  printf("Aptr = %p\n", (void *) Aptr);
  printf("c = %d\n", c);
  printf("Cptr = %p\n", (void *) Cptr);



  //printf("*Bptr = %d\n", Bptr);
  return 0;
}
