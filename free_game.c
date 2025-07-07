/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:45:06 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/07 16:42:03 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_game(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->ground_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	i = 0;
	while (i < game->collectible)
	{
		mlx_destroy_image(game->mlx, game->img_collectible[i]);
		i++;
	}
	free(game->collectible);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
void free_map(char **map)
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
