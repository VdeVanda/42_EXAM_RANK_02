/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char	**ft_split(char *str);
*/

#include <stdio.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		word;
	int		letter;

	arr = malloc(sizeof(char *) * WD_NUM);
	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			letter = 0;
			arr[word] = malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
				arr[word][letter++] = str[i++];
			arr[word][letter] = '\0';
			word++;
		}
		else
			i++;
	}
	arr[word] = '\0';
	return (arr);
}
/* 
int	main(void)
{
	char	*str;
	char	**split_str;

	str = "   lorem   ipsum dolor  consectetur.   Suspendisse  ";
	split_str = ft_split(str);
	while (*split_str)
		printf("%s\n", *split_str++);
	return (0);
}
*/