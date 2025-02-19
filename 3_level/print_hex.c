/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

void	print_hex(int number)
{
	if (number >= 16)
		print_hex(number / 16);
	write(1, &"0123456789abcdef"[number % 16], 1);
}

int	main(int argc, char **argv)
{
	int i;
	i = 0;
	int number;
	number = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			number = number * 10 + (argv[1][i] - '0');
			i++;
		}
		print_hex(number);
	}
	write(1, "\n", 1);
	return (0);
}