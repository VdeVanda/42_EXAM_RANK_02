/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	*ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int	*ft_rrange(int start, int end)

{
	int len;
	int *arr;
	int i;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	if (start <= end)
	{
		while (end >= start)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (end <= start)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	return (arr);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	*arr;
	int	size;

	if (argc != 3)
	{
		printf("Usage: %s <start> <end>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	arr = ft_rrange(start, end);
	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return (EXIT_SUCCESS);
}
