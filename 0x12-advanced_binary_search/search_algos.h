#ifndef _SEARCH_AlGOS_H_
#define _SEARCH_AlGOS_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int start, int end);

int search_in_array(int *array, int start, int end, int value);
int advanced_binary(int *array, size_t size, int value);

#endif