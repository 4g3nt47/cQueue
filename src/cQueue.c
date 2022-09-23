/**
 *-------------------------------------------------------------------
 *   A simple library that provides a generic way to work with queues
 * using void pointers. It uses first-in-first-out (FIFO).
 *                                                 Author: Umar Abdul
 *-------------------------------------------------------------------
 */

#include "cQueue.h"

queue *queue_init(size_t size){
  
  queue *q = malloc(sizeof(queue));
  if (q == NULL)
    return NULL;
  q->size = size;
  q->count = 0;
  q->pos = 0;
  q->items = malloc(sizeof(void *) * q->size);
  return q;
}

ssize_t queue_put(queue *q, void *e){

  if (queue_full(q))
    return -1;
  q->items[q->count] = e;
  q->count++;
  return (q->count - 1);
}

void *queue_get(queue *q){
  
  if (queue_exhausted(q))
    return 0;
  void *e = q->items[q->pos];
  q->pos++;
  return e;
}

unsigned short queue_full(queue *q){
  return (q->count >= q->size);
}

unsigned short queue_empty(queue *q){
  return (q->count == 0);
}

unsigned short queue_exhausted(queue *q){
  return (q->pos >= q->count);
}

unsigned short queue_seek(queue *q, size_t pos){

  if (pos >= q->size)
    return 0;
  q->pos = pos;
  return 1;
}

void queue_free(queue *q){
  
  q->size = 0;
  q->count = 0;
  q->pos = 0;
  for (int i = 0; i < q->count; i++)
    free(q->items[i]);
  free(q->items);
  free(q);
}
