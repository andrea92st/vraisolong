/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:36:12 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 20:31:46 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		h;
	int		w;

	if (argc != 2)
	{
		ft_putstr("error, donne map valid\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.map = read_map(argv[1]);
	if (!game.map)
		return (ft_putstr("Error\nImpossible de lire la map\n"), 0);
	is_map_valid(&game);
	h = game.map_h * TILE_SIZE;
	w = game.map_w * TILE_SIZE;
	game.moves = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, w, h, "So long");
	load_assets(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	init_len(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map || !game->map[0])
	{
		game->map_w = 0;
		return ;
	}
	game->map_h = 0;
	while (game->map[game->map_h])
		game->map_h++;
	while (game->map[0][i] && game->map[0][i] != '\n')
		i++;
	game->map_w = i;
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
