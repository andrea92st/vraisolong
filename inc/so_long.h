/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:12:34 by anfiorit          #+#    #+#             */
/*   Updated: 2025/10/02 22:21:40 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>
# include <minilibx-linux/mlx.h>

# define TILE_SIZE 128
# define BUFFER_SIZE 42

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define TILE_WALL   '1'
# define TILE_GROUND '0'
# define TILE_PLAYER 'P'
# define TILE_EXIT   'E'
# define TILE_ITEM   'C'

# define AW "assets/wall.xpm"
# define AG "assets/ground.xpm"
# define AP "assets/player.xpm"
# define AE "assets/exit.xpm"
# define AC "assets/item.xpm"

typedef struct s_game
{
	void		*mlx;
	void		*win;

	void		*item_img;
	void		*exit_img;
	void		*wall_img;
	void		*ground_img;
	void		*player_img;

	char		**map;
	int			map_w;
	int			map_h;

	int			player_x;
	int			player_y;
	int			exit_found;

	int			moves;
	int			counts;
	int			collectibles;
	char		direction;
}	t_game;

int		check_player(char **map);
int		check_exit(char **map);
int		check_wall(char **map);
int		check_item(char **map, t_game *game);
char	**copy_map(char **map);
void	flood_fill(char **map, t_game *game);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_build(char *stash, char *buffer);
void	ft_keep_rest(char **ptr);
char	*ft_create_line(char **ptr_stash, char **ptr_buffer, ssize_t count);
char	*get_next_line(int fd);
int		main(int argc, char **argv);
void	create_game(t_game *game);
int		count_lines(char *file);
int		handle_input(int keycode, t_game *game);
void	move_player(t_game *game, int next_x, int next_y, char direction);
void	exit_game(t_game *game);
char	**read_map(char *file);
void	load_assets(t_game *game);
void	put_player_sprite(t_game *game, int px, int py);
void	fill_tile(t_game *game, int x, int y, char tile);
void	render_map(t_game *game);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	*ft_memset(void *s, int c, size_t len);
void	is_map_valid(t_game *game);
void	init_len(t_game *game);
void	find_pos_player(char **map, t_game *game);
void	map_not_valid(char **map, t_game *game);
void	free_map(char **map);
int		is_map_allowed(char **map);
int		is_char_allowed(char c);
void	read_map2(int fd, char **map, int line, int i);
int		check_first_line(char **map, int *len);
int		is_map_rectangular(char **map);
int		close_window(t_game *game);
ssize_t	gnl_fill_stash(int fd, char **stash);

#endif