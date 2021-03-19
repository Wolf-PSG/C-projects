#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <unistd.h>
#include <pthread.h>

/******************************************************************************
  Demonstrates how to crack an encrypted password using a simple
  "brute force" algorithm. Works on passwords that consist only of 2 uppercase
  letters and a 2 digit integer.

  Compile with:
    cc -o CrackAZ99 CrackAZ99.c -lcrypt

  If you want to analyse the output then use the redirection operator to send
  output to a file that you can view using an editor or the less utility:
    ./CrackAZ99 > output.txt

  Dr Kevan Buckley, University of Wolverhampton, 2018 Modified by Dr. Ali Safaa 2019
******************************************************************************/

int count = 0; // A counter used to track the number of combinations explored so far
int checker = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void substr(char *dest, char *src, int start, int length)
{
  memcpy(dest, src + start, length);
  *(dest + length) = '\0';
}

struct argStruct
{
  char *password;
  int starting_letter;
} arguments;

void *crack(void *args)
{
  struct argStruct *passed_struct = (struct argStruct *)args;
  pthread_mutex_lock(&mutex1);
  int *x, *y, *z; // Loop counters
  x = (int *)malloc(sizeof(int));
  y = (int *)malloc(sizeof(int));
  z = (int *)malloc(sizeof(int));
  char(*salt)[7] = malloc(1000 * sizeof(char)); // String used in hashing the password. Need space for \0 // incase you have modified the salt value, then should modifiy the number accordingly
  char plain[7];                                // The combination of letters currently being checked // Please modifiy the number when you enlarge the encrypted password.
  char *enc;                                    // Pointer to the encrypted password
  substr(*salt, passed_struct->password, 0, 6);
  *x = passed_struct->starting_letter;
  arguments.starting_letter++;
  pthread_mutex_unlock(&mutex1);
  printf("\nchecker: %d \n", checker);

  if (checker == 1)
  {
    return 0;
  }
  for (*y = 'A'; *y <= 'Z'; ++*y)
  {
    for (*z = 0; *z <= 99; ++*z)
    {
      sprintf(plain, "%c%c%02d", *x, *y, *z);
      pthread_mutex_lock(&mutex1);
      enc = (char *)crypt(plain, *salt);
      pthread_mutex_unlock(&mutex1);

      count++;
      printf("#%-8d%s %s\n", count, plain, enc);
      printf("\nPASSWORD IN STRCUT: %s\n", passed_struct->password);
      if (strcmp(passed_struct->password, enc) == 0)
      {
        printf("\n*******************FOUND *****************\n");
        checker = 1;
        printf("\nchecker: %d \n", checker);
        return 0;
      }
    }
  }
  free(x);
  free(y);
  free(z);
}

int main(int argc, char *argv[])
{
  arguments.password = "$6$AS$PMInoHPD5pADCpH8sE/OPTHDsk9Jh0ZnzB7dKc8d8YOPGfDS84kDzgI92k0Mjxm5fGJeDsHfhiEGeG/GeRiKR.";
  arguments.starting_letter = 'A';
  pthread_t thread1, thread2, thread3, thread4, thread5;
  pthread_create(&thread1, NULL, crack, &arguments);
  pthread_create(&thread2, NULL, crack, &arguments);
  pthread_create(&thread3, NULL, crack, &arguments);
  pthread_create(&thread4, NULL, crack, &arguments);
  pthread_create(&thread5, NULL, crack, &arguments);
  do
  {
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
  } while (checker == 0);

  // $6$AS$wKDMKDtx/s3ILNkNaRNFIM0w81/weD1UZ8daNhbQBXuj8L.7OY4trHnSraeizmFYrMwjlb1uRTPxu20rqhmMn/   ---  AA00
  // $6$AS$PMInoHPD5pADCpH8sE/OPTHDsk9Jh0ZnzB7dKc8d8YOPGfDS84kDzgI92k0Mjxm5fGJeDsHfhiEGeG/GeRiKR. --- EE00
  // $6$AS$OQH1Sn5DGubEf3P62pE/v19frTQKYDLAPO/FLRiyDGpvsI/dgp6dZlt8uW2whJ1wdc9VtOGEsmjqXZOjWZ6b/1
  printf("%d solutions explored\n", count);

  return 0;
}
