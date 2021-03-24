#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"


/**
 * create_node - Creates new npde
 *
 * @array: The array to transform to AVL Tree
 * @parent: Parent node
 * @start: The start of sub array
 * @end: The end of sub array
 * Return: the last newly created node
 */
avl_t *create_node(int *array, avl_t *parent, int start, int end)
{
	int mid;
	avl_t *newNode;

	if (start > end)
	return (NULL);
	mid = (start + end) / 2;

	newNode = malloc(sizeof(avl_t));
	if (!newNode)
	return (NULL);

	newNode->n = array[mid];
	newNode->parent = parent;
	newNode->left = create_node(array, newNode, start, mid - 1);
	newNode->right = create_node(array, newNode, mid + 1, end);

	return (newNode);
}


/**
 * sorted_array_to_avl - Transforms sorted array to AVL Tree
 *
 * @array: the array to be transformed
 * @size: array size
 * Return: the head of AVL Tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid, start, end;
	avl_t *head;

	if (!array)
	return (NULL);

	start = 0;
	end = size - 1;
	mid = (start + end) / 2;

	head = malloc(sizeof(avl_t));
	if (!head)
	return (NULL);
	head->n = array[mid];
	head->parent = NULL;
	head->left = create_node(array, head, start, mid - 1);
	head->right = create_node(array, head, mid + 1, end);
	return (head);
}
