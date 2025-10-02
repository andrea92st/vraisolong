/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:55:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 16:33:39 by fio              ###   ########.fr       */
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
	if(check_item(map, game) == 0)
		map_not_valid(map);
	if(check_player(map) != 1)
		map_not_valid(map);
	if(check_wall(map) != 0)
		map_not_valid(map);
	find_pos_player(map, game);
	flood_fill(map, game);
    if(game->exit_found == 0)
		map_not_valid(map);
    free_map(map);
}

void    find_pos_player(char **map, t_game *game)
{
	
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void map_not_valid(char **map)
{
	free_map(map);
	write(1, "Error, map non valide", 22);
	exit(EXIT_FAILURE);
}
