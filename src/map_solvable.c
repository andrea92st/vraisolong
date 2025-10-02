/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:55:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 20:55:22 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		i;
	int		y;
	char	**copy;

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

void	is_map_valid(t_game *game)
{
	char	**map;

	init_len(game);
	map = copy_map(game->map);
	if (check_exit(map) != 1)
		map_not_valid(map, game);
	if (check_item(map, game) == 0)
		map_not_valid(map, game);
	if (check_player(map) != 1)
		map_not_valid(map, game);
	if (check_wall(map) != 0)
		map_not_valid(map, game);
	if (is_map_rectangular(map) == 1 || is_map_allowed(map) == 0)
		map_not_valid(map, game);
	find_pos_player(map, game);
	flood_fill(map, game);
	if (game->exit_found == 0 || game->counts != game->collectibles)
		map_not_valid(map, game);
	free_map(map);
}

void	find_pos_player(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
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

int	is_map_allowed(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_char_allowed(map[y][x]) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_char_allowed(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'E')
		return (1);
	return (0);
}
