/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
		\ /
		/ \
 0001 | 0100
*/

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/*
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	unsigned char	octet;
	unsigned char	swapped;

	octet = 'A';
	write(1, "Original byte: ", 15);
	print_bits(octet);
	write(1, "\n", 1);
	swapped = swap_bits(octet);
	write(1, "Swapped  byte: ", 15);
	print_bits(swapped);
	write(1, "\n", 1);
}
*/