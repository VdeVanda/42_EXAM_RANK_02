/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

/*
NAME
		strpbrk - search a string for any of a set of bytes

char	*strpbrk(const char *s, const char *accept);

SYNOPSIS
		#include <string.h>

DESCRIPTION
		The  strpbrk() function locates the first occurrence in the string s of
		any of the bytes in the string accept.

RETURN VALUE
		The strpbrk() function returns a pointer to the byte in s that  matches
		one of the bytes in accept, or NULL if no such byte is found.
*/

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *s = "Test code";
	const char *accept = "d";

	printf("%s\n", strpbrk(s, accept));
	printf("%s\n", ft_strpbrk(s, accept));
	return (0);
}