#include "mavalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 10000
#define TEST_ITERATION 50
#define FILENAME "B4_BF.txt"

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
  int _ = remove(FILENAME);

  // TEST 1
  mavalloc_init( MAX_SIZE, BEST_FIT );
  for(int i = 0; i < TEST_ITERATION; i++)
  {
    //starts the timer
    start = clock();

    for(j = 0; j < MAX_SIZE; j++)
      ptrArr[j] = (char*) mavalloc_alloc( 1 );

    for(j = 0 ; j < MAX_SIZE; j++)
      mavalloc_free(ptrArr[j]);

    //ends the timer
    end = clock();

    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark4.c Test 1 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  export(time);
  mavalloc_destroy();


  // TEST 2
  for(i = 0; i < TEST_ITERATION; i++)
  {
    start = clock();

    mavalloc_init( MAX_SIZE, BEST_FIT );
    //malloc
    for(j = 0; j < MAX_SIZE; j++)
    {
      //alloc 256 times
      ptr1 = (char*)mavalloc_alloc( 1 );
      mavalloc_free(ptr1);
    }
    //yeet
    mavalloc_destroy();
    end = clock();
    
    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark4.c Test 2 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  export(time);



  // TEST 3
  for(i = 0; i < TEST_ITERATION; i++)
  {
    start = clock();

    //malloc
    for(j = 0; j < MAX_SIZE; j++)
    {
      mavalloc_init( MAX_SIZE, BEST_FIT );
      //alloc 256 times
      ptr1 = (char*)mavalloc_alloc( 1 );
      mavalloc_destroy();
    }
    //yeet

    end = clock();
    
    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    time[i] = timeTaken;
    printf("Time taken for benchmark4.c Test 3 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  export(time);
  
  return 0;
}
