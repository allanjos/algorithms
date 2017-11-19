#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void tree_create(Tree_t **tree)
{
  DEBUG("tree_create()\n");

  *tree = (Tree_t *) malloc(sizeof(Tree_t));

  (*tree)->root = NULL;

  (*tree)->count = 0;
}

TreeNode_t *tree_get_root(Tree_t *tree)
{
  return tree->root;
}

void tree_node_create(TreeNode_t **node, UserData_t data)
{
  DEBUG("tree_node_create()\n");

  *node = (TreeNode_t *) malloc(sizeof(TreeNode_t));

  (*node)->data = data;

  // Initially empty leaves

  (*node)->left = NULL;
  (*node)->right = NULL;
}

void tree_node_set_data(TreeNode_t *node, UserData_t data)
{
  DEBUG("node_set_data()\n");

  node->data = (UserData_t) data;
}

void tree_add_item(Tree_t *tree, TreeNode_t *node)
{
  DEBUG("tree_add_item()\n");

  if (tree == NULL) {
    DEBUG("Invalid tree.\n");

    return;
  }

  if (tree->root == NULL) {
    tree->root = node;
  }
  else {
    tree_node_add_item(tree->root, node);
  }
}

void tree_node_add_item(TreeNode_t *node, TreeNode_t *node_new)
{
  DEBUG("tree_node_add_item()\n");

  if (node == NULL) {
    return;
  }

  if (node_new->data < node->data) {
    if (node->left == NULL) {
      node->left = node_new;
    }
    else {
      tree_node_add_item(node->left, node_new);
    }
  }
  else {
    if (node->right == NULL) {
      node->right = node_new;
    }
    else {
      tree_node_add_item(node->right, node_new);
    }
  }
}

void tree_delete(Tree_t **tree)
{
  DEBUG("tree_delete()\n");

  if (*tree == NULL) {
    return;
  }

  tree_node_delete((*tree)->root);

  (*tree)->root = NULL;

  free(*tree);
}

void tree_node_delete(TreeNode_t *node)
{
  DEBUG("node_delete()\n");

  if (node == NULL) {
    return;
  }

  if (node->left != NULL) {
    tree_node_delete(node->left);

    node->left = NULL;
  }

  if (node->right != NULL) {
    tree_node_delete(node->right);

    node->right = NULL;
  }

  free(node);
}

TreeNode_t *tree_search_item(Tree_t *tree, UserData_t data)
{
  DEBUG("tree_search_item()\n");

  if (tree == NULL) {
    return NULL;
  }

  if (tree->root == NULL) {
    return NULL;
  }

  return tree_node_search_item(tree->root, data);
}

TreeNode_t *tree_node_search_item(TreeNode_t *node, UserData_t data)
{
  DEBUG("tree_node_search_item()\n");

  if (node == NULL) {
    return NULL;
  }

  if (node->data == data) {
    return node;
  }

  if (node->left != NULL && data < node->data) {
    return tree_node_search_item(node->left, data);
  }
  else if (node->right != NULL && data >= node->data) {
    return tree_node_search_item(node->right, data);
  }

  return NULL;
}

void tree_dump(Tree_t *tree)
{
  DEBUG("tree_dump()\n");

  if (tree->root == NULL) {
    DEBUG("Empty tree.\n");

    return;
  }

  tree_node_dump(tree->root);
}

void tree_node_dump(TreeNode_t *node)
{
  DEBUG("tree_node_dump()\n");

  if (node == NULL) {
    return;
  }

  DEBUG("node: %p, data: %d\n", node, node->data);

  if (node->left != NULL) {
    DEBUG("node at left side");

    tree_node_dump(node->left);
  }

  if (node->right != NULL) {
    DEBUG("node at right side");

    tree_node_dump(node->right);
  }
}