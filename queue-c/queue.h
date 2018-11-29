/**
 * A queue implementation.
 * 
 * \author Allann Jones
 */

#ifndef QUEUE_H
#define QUEUE_H

#define DEBUG printf

#define TRUE 1
#define FALSE 0

/**
 * Queue item
 */

typedef struct QueueItem_st {
  void *data; /**< User data. */

  struct QueueItem_st *next; /**< Location of the next item from queue. */
} QueueItem_t;

typedef struct Queue_st {
  struct QueueItem_st *root; /**< Location of the next item from queue. */

  struct QueueItem_st *last; /**< Location of the next item from queue. */

  unsigned int count;
} Queue_t;

typedef void * UserData_t;



void queue_item_create(QueueItem_t **queue_item);

void queue_item_set_data(QueueItem_t *queue_item, UserData_t data);

UserData_t queue_item_get_data(QueueItem_t *queue_item);

/**
 * Queue item destruction.
 */
void queue_item_destroy(QueueItem_t *queue_item);

/**
 * Queue creation.
 */
void queue_create(Queue_t **my_queue);

/**
 * Remove first item from queue.
 */

short queue_pop_item(Queue_t **my_queue);

/**
 * Add a item at the end of the queue.
 */

void queue_push(Queue_t **my_queue, QueueItem_t *item);

QueueItem_t *queue_get_first(Queue_t *my_queue);

/**
 * Destroy the queue.
 */

void queue_destroy(Queue_t **my_queue);

/**
 * Dump the queue.
 */

void queue_dump(Queue_t *my_queue);


#endif /* QUEUE_H */