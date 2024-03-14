/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:09:31 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/14 16:53:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include "./printf/ft_printf.h"
# define WALL "sprites/wall.xpm"
# define PLAYER "sprites/player.xpm"
# define COIN "sprites/coin.xpm"
# define EXIT "sprites/exit.xpm"
# define BUFFER_SIZE 33

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_image
{
	void	*wall_img;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
}	t_image;

typedef struct s_game
{
	char	**map;
	int		y_large;
	int		x_large;
	int		x_p;
	int		y_p;
	int		c_num;
	int		e_x;
	int		e_y;
	int		map_size;
}	t_game;

typedef struct s_map
{
	t_window	win;
	t_image		image;
	t_game		game;
}	t_map;

enum
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESCAPE = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
};


void	initialize_wall(void *mlx, t_image *map);
void	initialize_player(void *mlx, t_image *map);
void	initialize_coin(void *mlx, t_image *map);
void	initialize_exit(void *mlx, t_image *map);
void	render_wall(t_game *game, t_image *map, t_window *mlx);
void	render_player(t_game *game, t_image *map, t_window *mlx);
void	render_coin(t_game *game, t_image *map, t_window *mlx);
void	render_exit(t_game *game, t_image *map, t_window *mlx);

int	keyhook(int keycode, t_map *scene);
void	movement(t_map *scene, int dir);

int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, int start, int len);
char	*get_next_line(int fd);
char	*erase_newline(char *str);
char	*read_map(char *map, t_game **game);
char	**create_map(char *file, t_game **game);
void	checker(t_game *game);
void	*free_map(char **map);
void	check_format(char *argv);
void	check_width(t_game *game);
void	check_walls(t_game *game);
void	check_char(t_game *game);
void	check_coins(t_game **game);
void	check_exit(t_game *game);
void	check_player(t_game *game);
void	check_path(t_game *game);
void	assign_player_pos(t_game **game);
char	**duplicate_map(t_game *game);
void	flood_map(int x, int y, char **aux_map);
void	format_error(void);
void	width_error(void);
void	wall_error(void);
void	char_error(void);
void	coin_error(void);
void	exit_error(void);
void	player_error(void);
void	path_error(void);

#endif