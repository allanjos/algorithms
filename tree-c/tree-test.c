#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/**
 * Test program.
 */

int main(int argc, char *argv[]) {
  DEBUG("Create a tree\n");

  Tree_t *tree;

  tree_create(&tree);

  DEBUG("tree address: %p\n", tree);

  DEBUG("Creating tree nodes\n");

  TreeNode_t *item;

  tree_node_create(&item, 90);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 50);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 105);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 40);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 60);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 100);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  tree_node_create(&item, 110);
  DEBUG("node address: %p\n", item);
  tree_add_item(tree, item);

  DEBUG("Dumping tree..\n");

  tree_dump(tree);

  DEBUG("Searching in tree..\n");

  TreeNode_t *node_search = tree_search_item(tree, 110);

  if (node_search == NULL) {
    DEBUG("Node not found.\n");
  }
  else {
    DEBUG("Node is in tree.\n");
  }

  DEBUG("Destroying tree..\n");

  tree_delete(&tree);

  DEBUG("Finished.\n");

  return 0;
}
