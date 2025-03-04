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
    char *string;
    int len = 0;
    unsigned int positive;
    int temp_nbr = nbr;

    if (nbr <= 0)
        len++;
    while (temp_nbr != 0)
    {
        len++;
        temp_nbr /= 10;
    }

    string = malloc(sizeof(char) * (len + 1));
    if (!string)
        return (NULL);
    string[len] = '\0';

    if (nbr < 0)
    {
        string[0] = '-';
        positive = -nbr;
    }
    else
        positive = nbr;

    if (nbr == 0)
        string[0] = '0';

    while (positive != 0)
    {
        string[--len] = (positive % 10) + '0';
        positive = positive / 10;
    }
    return (string);
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
