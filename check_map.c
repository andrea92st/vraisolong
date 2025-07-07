/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:23:05 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/04 16:48:28 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int check_player(char **map)
{
    int x;
    int y;
    int count;

    count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {        
            if (map[y][x] == 'P')
                count++;
            x++;
        }
        y++;
    }
    return(count);
}

int check_exit (char **map)
{
    int y;
    int x;
    int count;

    count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {        
            if (map[y][x] == 'E')
                count++;
            x++;
        }
        y++;
    }
    return(count);
}

int check_item(char **map)
{
    int y;
    int x;
    int count;

    count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {        
            if (map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    return(count);
}

int check_wall(char **map)
{
    int x;
    int y;
    int count;
    int len;

    count = 0;
    x = 0;
    while (map[0][x])
    {
        if (map[0][x] != '1')
            count++;
        x++;
    }
    len = x;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][0] != '1' || map[y][len - 1] != '1')
                count++;
            x++;
        }
        y++;
    }
    y--;
    x = 0;
    while (map[y][x])
    {    
        if (map[y][x] != '1')
            count++;        
        x++;
    }
    return (count); 
}
