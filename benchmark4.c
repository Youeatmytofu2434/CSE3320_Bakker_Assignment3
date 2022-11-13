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
  for(int i=0; i<16; i++)
  {
    //starts the timer
    start = clock();
    //malloc
    mavalloc_init( 257, BEST_FIT );
    for(int j=0; j<256; j++)
    {
      //alloc 256 times
      ptr1 = (char*)mavalloc_alloc( 1 );
    }
    //yeet
    mavalloc_destroy();
    //ends the timer
    end = clock();

    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    printf("Time taken for benchmark4.c Test 1 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }

  i=0;
  j=0;
  for(i=0; i<16; i++)
  {
    start = clock();

    mavalloc_init( 257, BEST_FIT );
    //malloc
    for(j=0; j<256; j++)
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
    printf("Time taken for benchmark4.c Test 2 Iteration %d: %0.2f microseconds\n",i, timeTaken);
  }


  i=0;
  j=0;
  for(i=0; i<16; i++)
  {
    start = clock();

    //malloc
    for(j=0; j<256; j++)
    {
      mavalloc_init( 257, BEST_FIT );
      //alloc 256 times
      ptr1 = (char*)mavalloc_alloc( 1 );
      mavalloc_destroy();
    }
    //yeet

    end = clock();
    
    //1 million microseconds equals one second
    double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
    printf("Time taken for benchmark4.c Test 3 Iteration %d: %0.2f microseconds\n",i+1, timeTaken);
  }
  
  return 0;
}
