/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:00:33 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/24 19:20:49 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int gamberge(char **map)
{
	int check_count;

	check_count = 0;

	if (check_wall(**map) == 1)
		check_count++;
	if (check_exit(**map) == 1)
		check_count++;
	if (check_player(**map) == 1)
		check_count++;
	if (check_item(**map) == 1)
		check_count++;
	if (check_ground(**map) == 1)
		check_count++;
	if (check_count > 0)
		return (1);
	return(0)
}

static int count_lines(char *file)
{
	int		line;
	int		fd;
	char	*tmp;

	line += 0;
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
	if (line == 0)
		return (NULL);
	map = (char *) malloc (sizeof (char *) * (line + 1));
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd > 0)
		return (-1);
	while(i < line)
	{ 
		map[i] = get_next_line(fd);
		if (map[i] = NULL)
			break;
		i++;
	}
	map[i] == NULL;
	close(fd);
	return (map);
}