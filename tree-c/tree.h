#ifndef TREE_H
#define TREE_H

#define DEBUG printf

/** User custom data. */
//typedef void * UserData_t;
typedef int UserData_t;

/**
 * Tree item.
 */
typedef struct TreeNode_st {
  //UserData_t data; /**< User data. Add support for generic data. */
  int data;

  struct TreeNode_st *left; /**< Location of the next item from tree. */
  struct TreeNode_st *right; /**< Location of the next item from tree. */
} TreeNode_t;

/**
 *  Tree.
 */
typedef struct Tree_st {
  TreeNode_t *root; /**< Location of the next item from tree. */

  unsigned int count;
} Tree_t;

/** Tree creation. */
void tree_create(Tree_t **tree);

/** Create tree item. */
void tree_node_create(TreeNode_t **node, UserData_t data);

/** Set tree item data. */
void tree_node_set_data(TreeNode_t *node, UserData_t data);

/** Add a node to the tree. */
void tree_add_item(Tree_t *tree, TreeNode_t *node_new);

/** Add a node to a specific tree node. */
void tree_node_add_item(TreeNode_t *node, TreeNode_t *node_new);

/** Get root node. */
TreeNode_t *tree_get_root(Tree_t *tree);

/** Tree item destruction. */
void tree_node_delete(TreeNode_t *node);

/** Destroy the tree. */
void tree_delete(Tree_t **tree);

/** Search for an item in the tree. */
TreeNode_t *tree_search_item(Tree_t *tree, UserData_t data);

TreeNode_t *tree_node_search_item(TreeNode_t *node, UserData_t data);

/** Dump the tree. */
void tree_dump(Tree_t *tree);

/** Dump a tree node. */
void tree_node_dump(TreeNode_t *node);

#endif /* TREE_H */