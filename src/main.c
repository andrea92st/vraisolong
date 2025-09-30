/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:36:12 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/30 15:56:35 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	int     h;
	int     w;
	
	if (argc != 2)
	{
		ft_putstr("error, donne map valid\n");
		return(0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.map = read_map(argv[1]);
	if (!game.map)
		return(0);
	is_map_valid(&game);
	init_len(&game);
	h = game.map_h * TILE_SIZE;
	w = game.map_w * TILE_SIZE;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, w, h, "So long");
	load_assets(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	return(0);
}

void init_len(t_game *game)
{
	int i;

	i = 0;
	if (!game->map || !game->map[0])
	{
		game->map_w = 0;
		return;
	}
	game->map_h = 0;
	while (game->map[game->map_h])
		game->map_h++;
	while (game->map[0][i] && game->map[0][i] != '\n')
		i++;
	game->map_w = i;
}
