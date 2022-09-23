# cQueue

`cQueue` is a simple utility library for queueing items in a first-in-first-out (FIFO) order.

## Build

```sh
$ git clone https://github.com/4g3nt47/cQueue.git
$ cd cQueue
$ mkdir bin
$ make
```

The above will generate a `bin/cQueue.o` object file, which is all you need along with the header file at `src/cQueue.h` to use the library.

## Demo

`demo.c`
```c
#include <stdio.h>
#include "cQueue.h"

int main(int argc, char **argv){

  // Create a queue.
  queue *q = queue_init(10);
  if (q == NULL){
    printf("Error creating queue!\n");
    return 1;
  }
  // Load some values into it.
  printf("Before adding: pos: %d count: %d size: %d\n", q->pos, q->count, q->size);
  int *ptr;
  for (int i = 0; !queue_full(q) ; i++){
    ptr = malloc(sizeof(int));
    *ptr = i + 5;
    queue_put(q, ptr);
  }
  printf("After adding: pos: %d count: %d size: %d\n", q->pos, q->count, q->size);
  // Read items.
  while (!queue_exhausted(q)){
    ptr = queue_get(q);
    printf("Item %d: %d\n", q->pos - 1, *ptr);
  }
  printf("After reading: pos: %d count: %d size: %d\n", q->pos, q->count, q->size);
  queue_seek(q, 0); // Jump back to the start of the queue.
  printf("After seeking: pos: %d count: %d size: %d\n", q->pos, q->count, q->size);

  queue_free(q);
  return 0;
}
```

```sh
$ gcc demo.c cQueue.o -o demo
$ ./demo
Before adding: pos: 0 count: 0 size: 10
After adding: pos: 0 count: 10 size: 10
Item 0: 5
Item 1: 6
Item 2: 7
Item 3: 8
Item 4: 9
Item 5: 10
Item 6: 11
Item 7: 12
Item 8: 13
Item 9: 14
After reading: pos: 10 count: 10 size: 10
After seeking: pos: 0 count: 10 size: 10
```
