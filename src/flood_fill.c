/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:14:22 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/23 18:49:55 by fio              ###   ########.fr       */
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
static void fill(char **tab, int x, int y, char target, t_point size)
{
    if(x < 0 || y < 0 || x >= size.x || y >= size.y)
        return;
    if(tab[y][x] != target)
        return;
    tab[y][x] = 'F';
    fill(tab, x + 1, y, target, size);
    fill(tab, x - 1, y, target, size);
    fill(tab, x, y + 1, target, size);
    fill(tab, x, y - 1, target, size);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];
    if(target == 'F')
        return ;
    fill(tab, begin.x, begin.y, target, size);
}

int check_map_solvable(char **map)
{
    char    **map_copy;
    int     y;
    int     x;

    y = 0;
    map_copy = copy_map(map);
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if(map_copy[y][x] == 'P')
                flood_fill(map_copy, x, y);
            x++;
        }
        y++;
    }
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if(map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
                return (1);
            x++;
        }
        y++;
    }
    return (0); 
}
