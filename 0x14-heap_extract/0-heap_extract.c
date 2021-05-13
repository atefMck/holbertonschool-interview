#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * swap_nodes - function that swaps two nodes
 * 
 * @node_a: first node
 * @node_b: second node
 * Return: 1 on success 0 on fail
 */
int swap_nodes(heap_t *node_a, heap_t *node_b)
{
  heap_t *tmp = node_a;
  if (!node_a || ! node_b)
  return (0);
  node_a = node_b;
  node_b = tmp;
  return (1);
}

/**
* get_min_heap - fetches the minimum heap
* @root: root of the heap
* Return: return the minimum heap node
*/
heap_t *get_min_heap(heap_t *root)
{
  heap_t *tmp = root;
  if (!tmp)
  return (0);
  if (tmp->left && tmp->n < tmp->left->n)
  get_min_heap(tmp->left);
  else if (tmp->right && tmp->n < tmp->right->n)
  get_min_heap(tmp->right);
  return (tmp);
}

/**
* heapify - heapifies a binary tree
* @root: root of the tree
* Return: null on failure
*/
void heapify(heap_t *root)
{
  heap_t *tmp = root;
  if (!tmp)
  return;
  if (tmp->left && tmp->n < tmp->left->n)
  {
    swap_nodes(tmp, tmp->left);
    heapify(tmp);
  }
  else if (tmp->right && tmp->n < tmp->right->n)
  {
    swap_nodes(tmp, tmp->right);
    heapify(tmp);
  }
  else
  return;
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * 
 * @root: double pointer to the root node of the heap
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
  heap_t *tmp = (void *) root;
  heap_t *min;
  int extracted;
  if (!tmp)
  return (0);
  extracted = tmp->n;
  min = get_min_heap(tmp);
  swap_nodes(tmp, min);
  free(tmp);
  heapify(min);
  return (extracted);
}
