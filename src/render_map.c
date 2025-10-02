/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:07:22 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 20:54:20 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *game)
{
	int	h;
	int	w;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, AW, &w, &h);
	game->ground_img = mlx_xpm_file_to_image(game->mlx, AG, &w, &h);
	game->item_img = mlx_xpm_file_to_image(game->mlx, AC, &w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, AE, &w, &h);
	game->player_img = mlx_xpm_file_to_image(game->mlx, AP, &w, &h);
}

void	fill_tile(t_game *game, int x, int y, char tile)
{
	int	px;
	int	py;

	px = (x * TILE_SIZE);
	py = (y * TILE_SIZE);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->ground_img, px, py);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, px, py);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->item_img, px, py);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, px, py);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, px, py);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			fill_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}
