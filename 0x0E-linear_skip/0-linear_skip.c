#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - performs linear skip search on a linked list
 *
 * @list: head of the list
 * @value: the value to search for
 * Return: the wanted node or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *tmp;

	express = tmp = list;

	if (!list)
	return (NULL);
	while (express->express)
	{
		tmp = express;
		express = express->express;
		printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
		if (express->n >= value || !express->express)
		{
			if (!express->express && express->n < value)
			{
				tmp = express;
				while (express->next)
				express = express->next;
			}
			printf("Value found between indexes [%ld] and [%ld]\n", tmp->index,
			 express->index);
			while (tmp != express)
			{
				printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
				if (tmp->n == value)
				return (tmp);
				tmp = tmp->next;
			}
			if (express->n < value)
			printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
			return (NULL);
		}
	}
	return (NULL);
}
