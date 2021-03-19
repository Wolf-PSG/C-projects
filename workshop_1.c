#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// 1) using command line arguments 
// int main(int argc, char *argv[])
// {
//     // int age = 10;;
//     // char *name = "Parmjit";
//     printf("Hello %s, you are %s years old", argv[1], argv[2]);
// }

///2) Scanf
//using scanf
// void main()
// {
//     char name[20];
//     int age;
//     printf("Enter your name: ");
//     scanf("%s", name);
//     printf("Enter your age: ");
//     scanf("%d", &age );
//     printf("Hello %s, you are %d years old", name, age);
// }

/// 3) BishBashBosh using string concatination

// void main(int argc, char *argv[])
// {
//   for(int n =1; n <=100; n++)
//   {
//     char output[20]="";
//     if(n % 2 == 0){
//         strcat(output, "Bish");
//     }
//     if(n % 3 == 0) {
//         strcat(output, "Bash");
//     }
//     if(n % 5 == 0) {
//         strcat(output, "Bosh");
//     }
//     if (output[0] == '\0') { //checks if output is empty -- fastest
//         printf("%d\n", n);
//     } else {
//         printf("%s\n", output);
//     }
//   }
// }

/// 4) Swap
// int swap(int *a, int *b) {
// 	int temp = 0; 
// 	int *value1; 
// 	int *value2;
// 	value1 = a; //value1 = location of a in memory
// 	value2 =  b; // value2 = location of b in memory
// 	temp = *value1; // temp is = to the memory location
// 	printf("temp: %d\n", temp);
// 	*value1 = *value2; //memory location of value1 (which is = to a) is now = to memory location of value2 (which is = to b)
// 	printf("value1: %d\n", *a);
// 	*value2 = temp;
// 	printf("value2: %d\n", *b);
// 	return 0;
// }

// int main(void)
// {
//   int a = 3;
//   int b = 4;
  
//   printf("a is %d and b is %d\n", a, b);
// 	swap(&a, &b);

//   printf("a is now %d and b is now %d\n", a, b);
// }

/// 5) Malloc
// void main(int argc, char *argv[])
// {
// 	int *size;
// 	int value;
// 	do {
// 	printf("choose a size between 1 and 50: ");
// 	scanf("%d", &value);
// 	} while(value>50 || value<1 );
	
// 	size = (int *) malloc(value); //to check if malloc allocated the memory
// 	if(size){
// 		printf("success\n");
// 	} else {
// 		printf("fail\n");
// 	}
//   for (int i=1; i <= value; i++){
//     size[i] = rand(); 
//     printf("%d is %d\n", i, size[i]);
//   }
// 	free(size);
// }

//6) Multithreading
both threads count to 10

void *threadJob(void *p){
  for(int i=0; i<=10; i++){
    printf("Thread ID %ld: i=%d\n", pthread_self(), i);
    usleep(1000);
  }
}

void main(int argc, char *argv[]){
		int value = atoi(argv[1]); //converts string to int
		pthread_t thrID[value]; //creates that number of pthreads
		for(int i = 0; i<=value; i++) { //creates the thread with the ID of i and is to run the function threadA
			pthread_create(&thrID[i], NULL, threadJob, NULL);
		}
		for(int i = 0; i<=value; i++) { //runs the threads 
					pthread_join(thrID[i], NULL);
		}
}