/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:57:26 by vabatist          #+#    #+#             */
/*   Updated: 2025/02/12 18:15:45 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
        int i;
        i = 0;

        while (s2[i])
        {
            s1[i] = s2[i];
            i++;
        }
        s1[i] = '\0';
        return (s1);
}

int main(void)
{
    char str1[] = "ola";
    char str2[] = "mundo";
    printf("%s\n", ft_strcpy(str1, str2));
}