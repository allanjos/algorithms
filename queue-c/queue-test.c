/**
 * A queue implementation.
 * 
 * \author Allann Jones
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Test program.
 */

int main(int argc, char *argv[]) {

  DEBUG("\nCreate a queue\n");

  Queue_t *queue_1;

  queue_create(&queue_1);

  DEBUG("queue address: %p\n", queue_1);


  for (int item_index = 0; item_index < 5; item_index++) {
    DEBUG("\nCreate a queue item\n");

    QueueItem_t *item_1;

    queue_item_create(&item_1);

    DEBUG("item address: %p\n", item_1);


    DEBUG("\nQueue item data\n");

    int *data = (int *) malloc(sizeof(int));

    *data = item_index;

    queue_item_set_data(item_1, (UserData_t) data);

    //item_1->data = (UserData_t) data;


    DEBUG("\nAdd a item to the queue\n");

    queue_push(&queue_1, item_1);
  }


  DEBUG("\nDump queue content\n");

  queue_dump(queue_1);


  DEBUG("\nConsuming queue content\n");

  do {
    QueueItem_t *item = queue_get_first(queue_1);

    if (!item) {
      printf("There is no more items to consume\n");

      break;
    }

    printf("Item consumed..\n");
  } while (queue_pop_item(&queue_1));


  DEBUG("\nDestroy the queue\n");

  queue_destroy(&queue_1);


  return 0;
}