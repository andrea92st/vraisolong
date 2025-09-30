/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:55:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/30 16:03:44 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **map)
{
    int     i;
    int     y;
    char    **copy;

    y = 0;
    while (map[y])
        y++;
    copy = malloc(sizeof(char *) * (y + 1));
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (i < y)
    {
        copy[i] = ft_strdup(map[i]);
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void is_map_valid(t_game *game)
{
	char	**map;

	map = copy_map(game->map);
	if(check_exit(map) != 1)
		map_not_valid(map);
	if(check_item(map) == 0)
		map_not_valid(map);
	if(check_player(map) != 1)
		map_not_valid(map);
	if(check_wall(map) != 0)
		map_not_valid(map);
	find_pos_player(map, &game);
	if(flood_fill(map) != 1)
		map_not_valid(map);
}

int find_pos_player(char **map, t_game *game)
{
	
    int x;
    int y;
    int count;

    count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == 'P')
                count++;
            x++;
        }
        y++;
    }
    return(count);
}

void map_not_valid(char **map)
{
	free_map(map);
	write(1, "Error, map non valide", 22);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}