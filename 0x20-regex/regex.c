#include <stdlib.h>
#include <stdio.h>
#include "regex.h"


/**
 * last_index_char - Get index of last occurence of char in string
 * @s: The string to search in
 * @c: The char to search for
 * @i: The index where to start
 * Return: The index of occurence if exists else -1
 */
int last_index_char(char const *s, char c, int i)
{
	int idx = -1;

	while (s[i])
	{
		if (s[i] == c)
		return i;
		i++;
	}
	return (idx);

}

/**
 * regex_match - matches string with pattern
 * @str: string to match
 * @pattern: the pattern to match
 * Return: 1 if matches else 0
 */
int regex_match(char const *str, char const *pattern)
{
    int i = 0;
	int j = 0;

	while (pattern[i] || str[j])
	{
		if (pattern[i] == str[j])
		{
			i++;
			j++;
			if (!pattern[i] && !str[j])
			return (1);
		}
        else if (pattern[i] == '.')
        {
            i++;
			j++;
			if (!pattern[i] && !str[j])
			return (1);
        }
        else if (pattern[i] == '*')
		{
			while (pattern[i] == '*')
			{
				i++;
				if (!pattern[i])
				return (1);
			}
			j = last_index_char(str, pattern[i], j - 1);
			if (j == -1)
			return (0);
		}
        else if (pattern[i + 1] && pattern[i + 1] == '*')
        i += 2;
		else
		return (0);
	}
	return (1);
    
    
}
