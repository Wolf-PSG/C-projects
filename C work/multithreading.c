#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct limits{

long long start;
long long end;

};

//

void main(){

struct limits threadVariables[2];
threadVariables[0].start = 0;
threadVariables[0].end = 50000

threadVariables.start = 50000
threadVariables.end= = 10000

long long *sqList = malloc(sizeof(long long) * 10000);

for (long long i = threadVariables[0].start; i<threadVariables[0].end; i++){
	sqList[i] = i * i;
	}

for (long long i = threadVariables[1].start; i <threadVariables[1]; i++){
	sqList[i] = i * i;
	}

for (long long i = 0; i<10000;i++){
	print("%ld\n",sqList[i]);
	}

}
