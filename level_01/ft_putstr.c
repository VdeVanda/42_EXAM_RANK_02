/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:40:27 by vabatist          #+#    #+#             */
/*   Updated: 2025/02/12 17:55:57 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    } 
}

int main(void)
{
    ft_putstr("ola");
    write(1, "\n", 1);
    return (0);
}