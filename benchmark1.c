#include "mavalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 10000
#define TEST_ITERATION 50
#define FILENAME "B1_Malloc.txt"


// function export
// @description: export the time to complete each test 
//  to a file 
// @parameter: a double array
void export(double timeArr[])
{
  FILE * fp;  
  fp = fopen( FILENAME, "a");
  for (int i = 0; i < TEST_ITERATION; i++)
    fprintf(fp, "%0.2f\n", timeArr[i]);
  fprintf(fp, "%s\n", "********************");
  fclose(fp);
}

int main( int argc, char * argv[] )
{
  clock_t start, end;
  char * ptr1;
  char * ptrArr [MAX_SIZE];
  double time[TEST_ITERATION];
  

  int i, j;
  // remove file to avoid appending to existing file  
  int _ = remove(FILENAME);

  // TEST 1
  for(i = 0; i < TEST_ITERATION; i++)
  {
    //starts the timer
    start = clock();

    //malloc
    for(j = 0; j < MAX_SIZE; j++)
    {
      ptrArr[j] = (char*)malloc( 1 );
    }
    for(j = 0; j < MAX_SIZE; j++)
    {
      free(ptrArr[j]);
    }
    //ends the timer
    end = clock();

    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark1.c Test 1 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  export(time);
  

  // TEST 2
  for(i = 0; i < TEST_ITERATION; i++)
  {
    start = clock();

    //malloc
    for(j = 0; j < MAX_SIZE; j++)
    {
      ptr1 = (char*)malloc( 1 );
      
      free(ptr1);
    }

    end = clock();
    
    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark1.c Test 2 Iteration %d: %0.2f microseconds\n",i+1, timeTaken);
  }
  export(time);

  // TEST 3
  char * ptrArr2 [MAX_SIZE];
  char * ptr2;
  char * ptr3;
  char * ptr4;
  char * ptr5;
  for(i = 0; i < TEST_ITERATION; i++)
  {
    start = clock();
    
    for(j = 0; j < (MAX_SIZE / 2); j++)
    {
      if(j % 2 == 0)
        ptrArr2[j] = (char*) malloc(1);
    }
    ptr2 = (char*) malloc((MAX_SIZE / 2) / 3);
    ptr3 = (char*) malloc((MAX_SIZE / 2) / 3);
    ptr4 = (char*) malloc((MAX_SIZE / 2) / 3);
    free(ptr3);
    free(ptr2);
    ptr5 = (char*) malloc((MAX_SIZE / 10));

    for(j = 0; j < (MAX_SIZE / 10); j++)
    {
      ptrArr[j] = (char*) malloc(1);
    }

    for(j = 0; j < (MAX_SIZE / 2); j++)
    {
      if(j % 2 == 0)
        free(ptrArr2[j]);
    } 

    for(j = 0; j < (MAX_SIZE / 10); j++)
    {
      free(ptrArr[j]);
    }
    free(ptr4);
    free(ptr5);

    end = clock();
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark2.c Test 3 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  export(time);

  return 0;
}
