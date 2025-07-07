/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:12:34 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/04 16:39:15 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define TILE_SIZE 32
# define KEY_ESC 65037
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100

typedef struct s_sprite_player {
    void    *up;
    void    *down;
    void    *right;
    void    *left;
}   t_sprite_player;

typedef struct s_game {
    void            *mlx;
    void            *win;
    
    void            *item_img;
    void            *exit_img;
    void            *wall_img;
    void            *ground_img;

    t_sprite_player player;
    char            **map;

    int             player_x;
    int             player_y;

    int             collectibles;
    int             anim_frame;
    
    char             direction;
}   t_game;

int     check_player(char **map);
int     check_exit(char **map);
int     check_wall(char **map);
int     check_item(char **map);
char    **copy_map(char **map);
void    flood_fill(char **map, int x, int y);
int     check_map_solvable(char **map);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_build(char *stash, char *buffer);
void	ft_keep_rest(char **ptr);
char	*ft_create_line(char **ptr_stash, char **ptr_buffer, ssize_t count);
char	*get_next_line(int fd);
int     main (int argc, char **argv);
void    create_game(t_game *game);
int     gamberge(char **map);
int     count_lines(char *file);
char    **read_map(char *file);
void    load_assets(t_game *game);
void	put_player_sprite(t_game *game, int px, int py);
void    fill_tile(t_game *game, int x, int y, char tile);
void    render_map(t_game *game);

#endif