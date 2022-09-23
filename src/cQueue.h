/**
 *------------------------------------
 * Header file for the cQueue library.
 *                  Author: Umar Abdul
 *------------------------------------
 */

#ifndef CQUEUE_H
#define CQUEUE_H

#include <stdlib.h>

typedef struct {
  size_t size; // The max size of the queue.
  size_t count; // The number of items in the queue.
  size_t pos; // Index of the value to read next.
  void **items; // Pointer to all the items in the queue.
} queue;

// Create a queue for a maximum of `size` elements.
queue *queue_init(size_t size);

// Add the item `q` to the end of a queue. Returns the offset of the item, -1 on error.
ssize_t queue_put(queue *q, void *e);

// Get the next item in a queue. Returns NULL on error.
void *queue_get(queue *q);

// Remove an item at the given offset.
void *queue_remove(queue *q, size_t pos);

// Returns 1 if there is no space in the queue for a new item.
unsigned short queue_full(queue *q);

// Returns 1 if the queue is empty.
unsigned short queue_empty(queue *q);

// Returns true if the end of the queue has been reached.
unsigned short queue_exhausted(queue *q);

// Jump to an offset in the qeueu. Returns 1 on success.
unsigned short queue_seek(queue *q, size_t pos);

// Free the queue and all the pointers added to it.
void queue_free(queue *q);

#endif // CQUEUE_H
