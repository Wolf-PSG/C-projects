#include <stdio.h>
/*
int main()
{
   printf("\n Parmjit Singh Gill \n 1811952 \n Computer Science \n");
}

int main() {

    char name[] = "Parmjit Singh Gill";
    int id = 1811952;
    char degree[] = "Computer Science";
    printf("\nMy name is %s \n My student ID is %d \n My degree is %s\n", name, id, degree);
}



int main() {

  int width = 20;
  int height = 5;

  int perminter = ((width * 2) + (height * 2));

  printf("\n The perminter of the rectangle is %d\n", perminter);
}



int main() {

    int radius = 3;
    double pi = 3.1415;

    double circumference = (2 * pi * radius );

    double area = (pi * (radius*radius));

    printf("\nThe ircumference of this circle is %lf\n", circumference);

    printf("\nThe area of this circle is %lf\n", area);

}



int main() {

    int value = 2090000000

    int year = (24*60*60*365);
    //int month = 2592000;
    int weeks = 604800;
    int days = 86400;
    int hour = 3600;
    int minutes = 60;

}
//Q6 - Counting the amount of odd numbers within a list of 30 numbers
int main() {
    int list = 1;
    int amount = 1;
    while(list<31,list++){
      if (list % 2 == 1){
        amount++;
        if (list>29){
          break;
        }
      }else{
        if (list>29){
          break;
        }
      }
    } printf("\nThere are %d odd numbers in 30 numbers\n", amount);



}
*/
//Q7 conversion deciaml to binary to hex and octal

int main()
{
  int n, c, k;

  printf("Enter an integer in decimal number system\n");
  scanf("%d", &n); //asks the user to enter an integer with scanf function which is then assigned to int n

  printf("%d in binary number system is:\n", n);

  for (c = 31; c >= 0; c--) { //The for loop actually checks if c is >=0 and then decrements of c
    k = n >> c; //right shift dived n with 2^c (2 to the power of c)

    if (k & 1) //checks if k is = 1 and the bit is 1 then prints the value of 1
      printf("1");
    else //if the k is not = 1 then both are 0 and prints the value of 0
      printf("0");
  }

  printf("\n");

  return 0; //success status
}
