/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
		||
		\/
 0110  0100
*/

unsigned char	reverse_bits(unsigned char octet)

{
	unsigned int i;
	unsigned char rev;

	i = 8;
	rev = 0;
	while (i--)
	{
		rev = (rev << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (rev);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned char bit = 0;
	unsigned char res = 'A';
	printf("Original: %c = 01000001\n", res);
	printf("Reversed: A = ");

	int i = 8;
	while (i--)
	{
		unsigned char res = reverse_bits((unsigned char)'A');
		bit = (res >> i & 1) + '0';
		printf("%c", bit);

	}
	printf("\n");
} */