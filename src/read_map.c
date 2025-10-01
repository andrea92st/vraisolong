/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:00:33 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/01 20:43:29 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void delete_eol(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}	
}

static int is_map_rectangular(char **map)
{
	int	i;
	int	h;
	int	len;

	len = 0;
	while(map[0][len])
		len++;
	h = 1;
	while(map[h])
	{
		i = 0;
		while(map[h][i])
			i++;
		if (i != len)
			return (1);
		h++;
	}
	return (0);
}

int count_lines(char *file)
{
	int		line;
	int		fd;
	char	*tmp;

	line = 0;
	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((tmp = get_next_line(fd)) != NULL)
	{
		line++;
		free(tmp);
	}
	close(fd);
	return(line);
}
char **read_map(char *file)
{
	int     line;
	char    **map;
	int     fd;
	int     i;

	i = 0;
	line = count_lines(file);
	if (line <= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc (sizeof (char *) * (line + 1));
	if (map == NULL)
	{
		close(fd);
		return (NULL);		
	}
	while(i < line)
	{ 
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break;
		delete_eol(map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	if(is_map_rectangular(map) == 1)
		map_not_valid(map);
	return (map);
}

