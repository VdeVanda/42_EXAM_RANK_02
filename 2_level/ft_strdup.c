/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char	*ft_strdup(char *src);
*/

/*
strdup: <string.h>
returns a pointer to a new string which is a duplicate of the string s.
Memory for the new string  is  obtained  with malloc,
and can be freed with free.
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*dup1;
	char	*dup2;

	str = "Hello, World!";
	dup1 = ft_strdup(str);
	dup2 = strdup(str);
	printf("ft_dup: %s\n", dup1);
	printf("or_dup: %s\n", dup2);
	free(dup1);
	free(dup2);
	return (0);
} */