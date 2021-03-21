//Structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employees{
  char names[20];
  double salary;
  double hours_of_work;
};

struct bookinfo{
  int acnum;
  char author[40];
  char book_title;
  int issue;
}

void main() {

  struct employees emp[2];
  strcpy( emp[0].names, "Parmjit");
  printf("%s\n", emp[0].names);
  emp[0].salary = 500;
  emp[0].hours_of_work = 15;
  printf("%f\n", emp[0].hours_of_work);
  printf("%f\n", emp[0].salary);
  if (emp[0].hours_of_work == 8) {
    emp[0].salary = emp[0].salary + 50;
    printf("%f\n", emp[0].salary);
  }else if (emp[0].salary <= 10) {
    emp[0].salary = emp[0].salary + 100;
    printf("%f\n", emp[0].salary);
  }else if (emp[0].salary >= 12) {
    emp[0].salary = emp[0].salary + 150;
    printf("%f\n", emp[0].salary);


  }



}
