/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

// Função para escrever um número na saída padrão
void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

// Função para verificar se um número é primo
int	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// Função para converter string para número
int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}

	int num = ft_atoi(argv[1]);
	int sum = 0;
	int i = 2;
	while (i <= num)
	{
		if (is_prime(i))
		{
			sum += i;
		}
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}