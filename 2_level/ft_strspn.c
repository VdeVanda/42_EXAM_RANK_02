/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

/*A função strspn (string span) é uma função da biblioteca string.h
que calcula o comprimento do segmento inicial de uma string que
CONTÉM APENAS os caracteres especificados no conjunto de caracteres.*/

#include <stdio.h> // Needed for size_t

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}
/*
#include <string.h>  // Needed for original strcspn

int	main(void)
{
	const char	*s1 = "Text strings";
	const char	*acc = "ex";

	printf("%ld\n", strspn(s1, acc));
	printf("%ld\n", ft_strspn(s1, acc));
	return (0);
}
*/