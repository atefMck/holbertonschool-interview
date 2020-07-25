#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list.
 * @number: the number to add.
 * Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *tmp, *iter;
	if (!head)
	return NULL;
	iter = *head;
	node = malloc(sizeof(listint_t));
	if (!node)
	return NULL;
	node->n = number;
	node->next = NULL;
	tmp = iter;

	while (iter) {
		if (iter->n > number)
		{
			tmp->next = node;
			node->next = iter;
			return node;
		}
		tmp = iter;
		iter = iter->next;
	}
	iter->next = node;
	return node;
}