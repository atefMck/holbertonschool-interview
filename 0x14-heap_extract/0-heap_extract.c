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
  int tmp = node_a->n;
  node_a->n = node_b->n;
  node_b->n = tmp;
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
  if (!tmp->left && !tmp->right)
  return (tmp);
  else if (tmp->left && tmp->right) 
  {
    if (tmp->left->n >= tmp->right->n)
    get_min_heap(tmp->left);
    else
    get_min_heap(tmp->right);
  }
  else if (tmp->left && !tmp->right)
  return (tmp->left);
  else if (!tmp->left && tmp->right)
  return (tmp->right);
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
  if (tmp->left && (tmp->n < tmp->left->n))
  {
    swap_nodes(tmp, tmp->left);
    heapify(tmp->left);
  }
  else if (tmp->right && (tmp->n < tmp->right->n))
  {
    swap_nodes(tmp, tmp->right);
    heapify(tmp->right);
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
  heap_t *tmp = *root;
  heap_t *min;
  int extracted;
  if (!tmp)
  return (0);
  extracted = tmp->n;
  min = get_min_heap(tmp);
  printf("Min heap: %d\n", min->n);
  swap_nodes(tmp, min);
  if (min->parent->left == min)
		min->parent->left = NULL;
	else
		min->parent->right = NULL;
  free(min);
  heapify(tmp);
  return (extracted);
}
