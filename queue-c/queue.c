/**
 * A queue implementation.
 * 
 * \author Allann Jones
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Queue item creation.
 */

void queue_item_create(QueueItem_t **queue_item) {
  DEBUG("queue_item_create()\n");

  *queue_item = (QueueItem_t *) malloc(sizeof(QueueItem_t));

  (*queue_item)->data = NULL;

  // Initially a isolated item

  (*queue_item)->next = NULL;
}

void queue_item_set_data(QueueItem_t *queue_item, UserData_t data) {
  DEBUG("queue_item_set_data()\n");

  queue_item->data = (UserData_t) data;
}

UserData_t queue_item_get_data(QueueItem_t *queue_item) {
  DEBUG("queue_item_set_data()\n");

  return queue_item->data;
}

/**
 * Queue item destruction.
 */

void queue_item_destroy(QueueItem_t *queue_item) {
  DEBUG("queue_item_destroy()\n");

  if (!queue_item) {
    return;
  }

  if (queue_item->data) {
    free(queue_item->data);
  }

  free(queue_item);
}

/**
 * Queue creation.
 */

void queue_create(Queue_t **my_queue) {
  DEBUG("queue_create()\n");

  *my_queue = (Queue_t *) malloc(sizeof(Queue_t));

  (*my_queue)->root = NULL;

  (*my_queue)->last = NULL;

  (*my_queue)->count = 0;
}

/**
 * Remove first item from queue.
 */

short queue_pop_item(Queue_t **my_queue) {
  if (*my_queue == NULL) {
    return FALSE;
  }

  if ((*my_queue)->root == NULL) {
    return FALSE;
  }

  DEBUG("queue_pop_item()\n");

  // First item

  QueueItem_t *item = (*my_queue)->root;

  DEBUG("item: %p\n", item);

  // Point to the next item
  if ((*my_queue)->root->next) {
    DEBUG("There is a next item.\n");

    (*my_queue)->root = (*my_queue)->root->next;
  }
  // List empty
  else {
    DEBUG("There is no more items.\n");

    (*my_queue)->root = NULL;

    (*my_queue)->last = NULL;
  }

  DEBUG("root: %p\n", (*my_queue)->root);

  // Free memory used by the first item

  queue_item_destroy(item);

  return TRUE;
}

/**
 * Add a item at the end of the queue.
 */

void queue_push(Queue_t **my_queue, QueueItem_t *item) {
  if (*my_queue == NULL || item == NULL) {
    return;
  }

  DEBUG("queue_push()\n");

  // Current root will be the second item from queue

  if ((*my_queue)->last) {
    (*my_queue)->last->next = item;

    (*my_queue)->last = (*my_queue)->last->next;
  }
  else {
    (*my_queue)->last = item;

    (*my_queue)->root = (*my_queue)->last;
  }


  (*my_queue)->count++;
}

QueueItem_t *queue_get_first(Queue_t *my_queue) {
  if (my_queue == NULL) {
    return NULL;
  }

  if (my_queue->root == NULL) {
    return NULL;
  }

  return my_queue->root;
}

/**
 * Destroy the queue.
 */

void queue_destroy(Queue_t **my_queue) {
  if (*my_queue == NULL) {
    return;
  }

  DEBUG("queue_destroy()\n");

  if ((*my_queue)->root != NULL) {
    int count = 0;

    while ((*my_queue)->root) {
      ++count;

      DEBUG("item %d: %p\n", count, (*my_queue)->root);

      queue_pop_item(my_queue);
    }
  }

  free(*my_queue);
}

/**
 * Dump the queue.
 */

void queue_dump(Queue_t *my_queue) {
  DEBUG("queue_dump()\n");

  if (my_queue->root == NULL) {
    DEBUG("No items on queue.\n");

    return;
  }

  QueueItem_t *root = my_queue->root;

  unsigned int item_index = 0;

  while (root) {
    ++item_index;

    DEBUG("item %d: %p\n", item_index, root);

    if (root->data) {
      DEBUG("item data %d: %d\n", item_index, *((int *)root->data));
    }

    if (!root->next) {
      break;
    }

    root = root->next;
  }
}