#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>

/**
 * getmax - Get maximum of array
 * @array: The array to sort
 * @size: Size of the array
 * Return: Always 0
 */
int getmax(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	return (max);
}

/**
 * counting_sort - counting sort an array
 * @array: The array to sort
 * @size: Size of the array
 * @sig: Significant digit
 * Return: Always 0
 */
void counting_sort(int *array, size_t size, size_t sig)
{
	int base[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;
	int j;
	int *digit = malloc(sizeof(int) * size);
	int *copy = malloc(sizeof(int) * size);

	if (!digit)
	return;
	if (!copy)
	return;

	memcpy(copy, array, sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		digit[i] = (array[i] / sig) % 10;
	}

	for (i = 0; i < size; i++)
	base[digit[i]]++;

	for (i = 0; i < 10; i++)
	{
		if (i != 0)
		base[i] += base[i - 1];
	}

	for (j = (int) size; j >= 0; j--)
	{
		array[base[digit[j]] - 1] = copy[j];
		base[digit[j]]--;
	}
	free(copy);
	free(digit);
}

/**
 * radix_sort - Radix sort an array
 * @array: The array to sort
 * @size: Size of the array
 * Return: Always 0
 */
void radix_sort(int *array, size_t size)
{
	int max, i;

	if (!array || size < 2)
	return;
	max = getmax(array, size);
	for (i = 1; max / i != 0; i *= 10)
	{
		counting_sort(array, size, i);
		print_array(array, size);
	}
}
