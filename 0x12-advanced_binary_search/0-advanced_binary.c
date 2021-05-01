#include "search_algos.h"

/**
 * print_array - prints a sub array
 * @array: is a pointer to the first element of the array
 * @start: is the start endex of sub array to print
 * @end: is the end index of sub array to print
 * Return: the index where value is located
 */
void print_array(int *array, int start, int end)
{
    int i;
    printf("Searching in array: ");
    for (i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i != end)
        printf(", ");
    }
    printf("\n");
}

/**
 * search_in_array - searches for a value in a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @start: is the start endex of sub array
 * @end: is the end index of sub array
 * @value: is the value to search for
 * Return: the index where value is located
 */
int search_in_array(int *array, int start, int end, int value)
{
    int mid = (start + end) / 2;
    int s, e;

    if (end >= start)
    {
        if (array[mid] == value && end == start)
        return (mid);
        print_array(array, start, end);
        if (array[mid] < value)
        {
            s = mid + 1;
            e = end;
        }
        if (array[mid] >= value)
        {
            s = start;
            e = mid;
        }
        
        return (search_in_array(array, s, e, value));
    }
    return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array)
    return (-1);
    if (!value)
    return (-1);
    return (search_in_array(array, 0, ((int) size) - 1, value));
}
