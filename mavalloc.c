// The MIT License (MIT)
// 
// Copyright (c) 2021, 2022 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES UTA OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#include <stdlib.h>
#include "mavalloc.h"


//typedef?
struct arenaMemory{
  int size;
  int next;
  int prev;
  int inuse;
  int* pointer;
  int type;
};

#define ALIGN4(s) (((((s) - 1) >> 2) << 2) + 4)

int mavalloc_init( size_t size, enum ALGORITHM algorithm ){
  if(size<0){
    return -1;
  }
  struct arenaMemory* arenaMem = NULL;
  arenaMem = (struct arenaMemory*)malloc(size);

  arenaMem->size=size;
  arenaMem->next=-1;
  arenaMem->prev=-1;
  arenaMem->inuse=0;

  switch(algorithm){
    case FIRST_FIT:
      arenaMem->type=1;
      break;
    case NEXT_FIT:
      arenaMem->type=2;
      break;
    case BEST_FIT:
      arenaMem->type=3;
      break;
    case WORST_FIT:
      arenaMem->type=4;
      break;
    default:
      break;
  }
  return 0;
}

void mavalloc_destroy( )
{
  //free(*arenaMemory);
  return;
}

void * mavalloc_alloc( size_t size )
{
  // only return NULL on failure
  return NULL;
}

void mavalloc_free( void * ptr )
{
  
  return;
}

int mavalloc_size( )
{
  int number_of_nodes = 0;

  return number_of_nodes;
}
