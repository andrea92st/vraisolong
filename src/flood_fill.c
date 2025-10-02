/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:14:22 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 17:56:42 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void fill(char **tab, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map_w || y >= game->map_h)
		return;
	if (tab[y][x] == '1' || tab[y][x] == 'F')
        return;
	if(tab[y][x] == 'E')
	{
		game->exit_found = 1;
		return ;
	}
	if (tab[y][x] == 'C')
        game->counts++;
	if (tab[y][x] == '0' || tab[y][x] == 'C' || tab[y][x] == 'P')
	{
		tab[y][x] = 'F';
		fill(tab, x + 1, y, game);
		fill(tab, x - 1, y, game);
		fill(tab, x, y + 1, game);
		fill(tab, x, y - 1, game);
	}
}

void  flood_fill(char **tab, t_game *game)
{
	game->exit_found = 0;
	game->counts = 0;
	fill(tab, game->player_x, game->player_y, game);
}
