#include "mavalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, char * argv[] )
{
  //starts the timer
  clock_t start = clock();
  
  //malloc
  mavalloc_init( 10001, FIRST_FIT );
  char * ptr1;
  for(int i=0; i<10000; i++)
  {
    //alloc 10k times
    ptr1 = (char*)mavalloc_alloc( 1 );
  }
  //yeet
  mavalloc_destroy();

  //ends the timer
  clock_t end = clock();

  //1 million microseconds equals one second
  double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
  printf("Time taken for benchmark 5: %0.2f microseconds\n", timeTaken);
  return 0;
}
