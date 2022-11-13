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
  char * ptr1;
  for(int i=0; i<10000; i++)
  {
    //alloc 10k times
    ptr1 = (char*)malloc( 1 );
    memset(ptr1, '.', 16);
  }
  //yeet
  free(ptr1);

  //ends the timer
  clock_t end = clock();

  //1 million microseconds equals one second
  double timeTaken = (double)((end-start)*1000000/CLOCKS_PER_SEC);
  printf("Time taken for benchmark 1: %0.2f microseconds\n", timeTaken);
  return 0;
}
