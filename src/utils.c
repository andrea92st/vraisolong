/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:40:32 by fio               #+#    #+#             */
/*   Updated: 2025/10/01 21:36:03 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (s);
}
static void	ft_int2char(int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_int2char(n % 10);
	}
	else
		ft_int2char(n);
}
