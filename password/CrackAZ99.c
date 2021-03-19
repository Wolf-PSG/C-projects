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
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
// struct arguments
// {
//   char password = ;
//   char author[50];
//   char subject[100];
//   int book_id;
// };
void substr(char *dest, char *src, int start, int length)
{
  memcpy(dest, src + start, length);
  *(dest + length) = '\0';
}

/**
 This function can crack the kind of password explained above. All combinations
 that are tried are displayed and when the password is found, #, is put at the 
 start of the line. Note that one of the most time consuming operations that 
 it performs is the output of intermediate results, so performance experiments 
 for this kind of program should not include this. i.e. comment out the printfs.
*/

void *crack(void *salt_and_encrypted)
{
  // char start_letter = "A";
  // char end_letter = "Z";
  pthread_mutex_lock(&mutex1);
  char *password = (char *)salt_and_encrypted;
  int x, y, z;   // Loop counters
  char salt[7];  // String used in hashing the password. Need space for \0 // incase you have modified the salt value, then should modifiy the number accordingly
  char plain[7]; // The combination of letters currently being checked // Please modifiy the number when you enlarge the encrypted password.
  char *enc;     // Pointer to the encrypted password
  substr(salt, password, 0, 6);
  // #pragma omp parallel for
  for (x = 'B'; x <= 'Z'; x++)
  {
    for (y = 'B'; y <= 'Z'; y++)
    {
      for (z = 0; z <= 99; z++)
      {
        sprintf(plain, "%c%c%02d", x, y, z);
        enc = (char *)crypt(plain, salt);
        count++;
        printf("#%-8d%s %s\n", count, plain, enc);
        if (strcmp(password, enc) == 0)
        {
          printf("#%-8d%s %s\n", count, plain, enc);
          return 0; //uncomment this line if you want to speed-up the running time, program will find you the cracked password only without exploring all possibilites
        }
      }
    }
  }
  pthread_mutex_unlock(&mutex1);
}

int main(int argc, char *argv[])
{
  pthread_t thread1, thread2, thread3, thread4, thread5;
  char *password = "$6$AS$PMInoHPD5pADCpH8sE/OPTHDsk9Jh0ZnzB7dKc8d8YOPGfDS84kDzgI92k0Mjxm5fGJeDsHfhiEGeG/GeRiKR.";
  pthread_create(&thread1, NULL, crack, (void *)password);
  // pthread_create(&thread2, NULL, crack, (void *)password);
  pthread_join(thread1, NULL);
  // pthread_join(thread2, NULL);
  // $6$AS$wKDMKDtx/s3ILNkNaRNFIM0w81/weD1UZ8daNhbQBXuj8L.7OY4trHnSraeizmFYrMwjlb1uRTPxu20rqhmMn/   ---  AA00
  // $6$AS$PMInoHPD5pADCpH8sE/OPTHDsk9Jh0ZnzB7dKc8d8YOPGfDS84kDzgI92k0Mjxm5fGJeDsHfhiEGeG/GeRiKR. --- EE00
  // $6$AS$OQH1Sn5DGubEf3P62pE/v19frTQKYDLAPO/FLRiyDGpvsI/dgp6dZlt8uW2whJ1wdc9VtOGEsmjqXZOjWZ6b/1
  // crack(); //Copy and Paste your ecrypted password here using EncryptShA512 program
  printf("%d solutions explored\n", count);

  return 0;
}
