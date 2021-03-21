#include <stdio.h>

int name() {
  int value1;
  int value2;
  scanf("Enter value 1%d\n", &value1);
  scanf("Enter value 2%d\n", &value2);
  return value1, value2;
}

void main(value1, value2){
  name();
  int sum = value1 + value2;
  printf("%d\n", sum);
}

/*
scanf("%d\n", &radius);
double area = (pi * (radius*radius));

printf("\nThe ircumference of this circle is %lf\n", circumference);

printf("\nThe area of this circle is %lf\n", area);
*/
