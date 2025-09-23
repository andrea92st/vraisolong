/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:07:22 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/04 16:39:26 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_assets(t_game *game)
{
    int h;
    int w;
    
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &h ,&w);
    game->ground_img = mlx_xpm_file_to_image(game->mlx, "assets/ground.xpm", &h ,&w);
    game->item_img = mlx_xpm_file_to_image(game->mlx, "assets/item.xpm", &h ,&w);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &h ,&w);
   
    game->player_left = mlx_xpm_file_to_image(game->mlx, "assets/pacman_sprite/pacman_left_open.xpm", &h ,&w);
    game->player_right = mlx_xpm_file_to_image(game->mlx, "assets/pacman_sprite/pacman_right_open.xpm", &h ,&w);
    game->player_up = mlx_xpm_file_to_image(game->mlx, "assets/pacman_sprite/pacman_up_open.xpm", &h ,&w);
    game->player_down = mlx_xpm_file_to_image(game->mlx, "assets/pacman_sprite/pacman_down_open.xpm", &h ,&w);
}

void	put_player_sprite(t_game *game, int px, int py)
{
	void *sprite = NULL;

	if (game->direction == 'W')
		sprite = game->player.up;
	else if (game->direction == 'S')
		sprite = game->player.down;
	else if (game->direction == 'A')
		sprite = game->player.left;
	else if (game->direction == 'D')
		sprite = game->player.right;
	if (sprite)
		mlx_put_image_to_window(game->mlx, game->win, sprite, px, py);
}

void fill_tile(t_game *game, int x, int y, char tile)
{
    int px;
    int py;

    px = (x * TILE_SIZE);
    py = (y * TILE_SIZE);
    if (tile == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->wall_img, px, py);
    else if (tile == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->exit_img, px, py);
    else if (tile == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->item_img, px, py);
    else if (tile == 'P')
        put_player_sprite(game, px, py);
    else 
        mlx_put_image_to_window(game->mlx, game->win, game->ground_img, px, py);
}

void render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            fill_tile(game, x, y, game->map[y][x]);
            x++;
        }
        y++;
    }
}



