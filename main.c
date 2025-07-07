/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:36:12 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/07 16:42:05 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        return(ft_putstr("error, nombre d'argument invalide"));

    game.map = read_map(argv[1]);
    game.mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 640, 820, "So long");
    load_assets(&game);
    render_map(&game);
    mlx_key_hook(game.win, handle_input, &game);
    mlx_loop(game.mlx);
}