/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

/*
A função strcspn em C é uma função da biblioteca padrão string.h
que serve para encontrar o comprimento do segmento inicial de uma
string que NÃO contém nenhum dos caracteres especificados em um
conjunto de caracteres.
*/

#include <stdio.h> // Needed for size_t

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

/*
#include <string.h>  // Needed for original strcspn

int	main(void)
{
	const char	*s1 = "Text strings";
	const char	*rej = "T";

	printf("%ld\n", strcspn(s1, rej));
	printf("%ld\n", ft_strcspn(s1, rej));
	return (0);
}
*/