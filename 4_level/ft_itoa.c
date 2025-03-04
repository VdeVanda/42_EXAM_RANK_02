/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

char *ft_itoa(int nbr)
{
    char *result;
    int len = 0;
    unsigned int num;
    int temp_nbr = nbr;

    if (nbr <= 0)
        len++;
    while (temp_nbr != 0)
    {
        len++;
        temp_nbr /= 10;
    }

    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    result[len] = '\0';

    if (nbr < 0)
    {
        result[0] = '-';
        num = -nbr;
    }
    else
        num = nbr;

    if (nbr == 0)
        result[0] = '0';

    while (num != 0)
    {
        result[--len] = (num % 10) + '0';
        num = num / 10;
    }
    return (result);
}

#include <stdio.h>

int main(void)
{
    int n = -123;
    char *str = ft_itoa(n);
    printf("%s\n", str);
    free(str);
    return (0);
}
