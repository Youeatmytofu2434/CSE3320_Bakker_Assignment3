#include "mavalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, char * argv[] )
{
  clock_t start, end;
  char * ptr1;

  int i=0;
  int j=0;
  for(i=0; i<16; i++)
  {
    //starts the timer
    start = clock();

    //malloc
    for(j=0; j<256; j++)
    {
      //alloc 256 times
      ptr1 = (char*)malloc( 1 );
    }
    //yeet
    free(ptr1);
    //ends the timer
    end = clock();

    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    printf("Time taken for benchmark1.c Test 1 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }
  

  i=0;
  j=0;
  for(i=0; i<16; i++)
  {
    start = clock();

    //malloc
    for(j=0; j<256; j++)
    {
      //alloc 256 times
      ptr1 = (char*)malloc( 1 );
      
      free(ptr1);
    }
    //yeet

    end = clock();
    
    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    printf("Time taken for benchmark1.c Test 2 Iteration %d: %0.2f microseconds\n",i+1, timeTaken);
  }

  
  return 0;
}
