/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;
	int match;
	char *s1;
	char *s2;

	i = 0;
	match = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					match = 0;
					while (s1[match] != s1[i])
						match++;
					if (match == i)
					{
						match = 0;
						while (s2[match] != s2[j])
							match++;
						if (match == j)
							write(1, &s1[i], 1);
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}