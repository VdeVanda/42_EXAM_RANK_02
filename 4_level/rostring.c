/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

void	rostring(char *str)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = start;
	while (str[end] && str[end] != ' ' && str[end] != '\t')
		end++;
	while (str[end] == ' ' || str[end] == '\t')
		end++;
	while (str[end])
	{
		if (!(str[end] == ' ' && (str[end + 1] == ' ' || str[end + 1] == '\t')))
		{
			write(1, &str[end], 1);
			i++;
		}
		end++;
	}
	if (i > 0)
		write(1, " ", 1);
	while (start < end && str[start] != ' ' && str[start] != '\t')
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		rostring(argv[1]);

	write(1, "\n", 1);
}