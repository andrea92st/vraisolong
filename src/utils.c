/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:40:32 by fio               #+#    #+#             */
/*   Updated: 2025/09/24 11:34:53 by fio              ###   ########.fr       */
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