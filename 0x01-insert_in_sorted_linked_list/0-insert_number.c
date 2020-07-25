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
	listint_t *node, *iter;
	if (head == NULL || *head == NULL)
	return NULL;
	iter = *head;
	node = malloc(sizeof(listint_t));
	if (node == NULL)
	return NULL;
	node->n = number;
	node->next = NULL;

	while(iter->next && iter->next->n < number)
	iter = iter->next;
	node->next = iter->next;
	iter->next = node;
	return node;
}