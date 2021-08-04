#include "holberton.h"
#include <stdio.h>


/**
 * last_index_char - Get index of last occurence of char in string
 * @s: The string to search in
 * @c: The char to search for
 * @i: The index where to start
 * Return: The index of occurence if exists else -1
 */
int last_index_char(char *s, char c, int i)
{
	int idx = -1;

	while (s[i])
	{
		if (s[i] == c)
		idx = i;
		i++;
	}
	return (idx);

}

/**
 * wildcmp - Compares two string with wild characters
 * @s1: String one
 * @s2: String 2
 * Return: 1 if identical else 0
 */
int wildcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s2[i] || s2[j])
	{
		if (s2[i] == s1[j])
		{
			i++;
			j++;
			if (!s2[i] && !s1[j])
			return (1);
		}
		else if (s2[i] == '*')
		{
			while (s2[i] == '*')
			{
				i++;
				if (!s2[i])
				return (1);
			}
			j = last_index_char(s1, s2[i], j);
			if (j == -1)
			return (0);
		}
		else
		return (0);
	}
	return (0);
}
