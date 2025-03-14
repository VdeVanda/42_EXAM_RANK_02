/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int	has_been_seen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
		char seen[256] = {0};
	int	len;
	int	i;

	if (argc == 3)
	{
		len = 0;
		i = 0;
		while (argv[1][i])
		{
			if (has_been_seen(seen, argv[1][i]) == 0)
			{
				seen[len++] = argv[1][i];
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (has_been_seen(seen, argv[2][i]) == 0)
			{
				seen[len++] = argv[2][i];
				write(1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
