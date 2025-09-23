/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:14:22 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/04 16:53:39 by anfiorit         ###   ########.fr       */
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
void flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'X')
        return;

    if (map[y][x] != '0' && map[y][x] != 'C' 
        && map[y][x] != 'E' && map[y][x] != 'P')
        map[y][x] = 'X';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
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
