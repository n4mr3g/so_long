/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 06:15:25 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 16:21:08 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILESIZE 48
# define RED "\x1b[31m"
# define BLUE	"\x1b[34m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define C_RST "\x1b[0m"

# include<fcntl.h>
# include"ft_printf.h"
# include"get_next_line.h"
# include"mlx.h"

typedef struct s_image {
	char	*relative_path;
	void	*mlx;
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct s_player {
	int		x;
	int		y;
	int		moves;
	int		collected;
}	t_player;

typedef struct s_enemy {
	int		x;
	int		y;
}	t_enemy;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	struct s_map	*map;
}	t_vars;

typedef struct s_map {
	t_player	*p;
	t_enemy		*e_arr;
	t_vars		*v;
	int			enemies;
	int			width;
	int			height;
	int			fd;
	int			has_player;
	int			has_exit;
	int			collectibles;
	char		**data;
}	t_map;

// Closing and memory freeing functions
void		free_map_data(t_map *map);
void		free_vars(t_vars *v);
int			close_win(t_vars *vars, int error_code);

// Game events
int			game_over(t_vars *v);
void		win_check(t_vars *v, t_player *p, int y, int x);
int			close_win(t_vars *vars, int error_code);

// Player movement
void		move_up(t_vars *v);
void		move_down(t_vars *v);
void		move_left(t_vars *v);
void		move_right(t_vars *v);

// Draw functions
t_image		*char_to_img(char c, t_vars *v);
void		draw_map(t_map *map, t_vars *vars, char *tiles, int first_time);

// Auxiliary functions
int			line_length(const char *str);
char		*line_dup(const char *s);

// Enemies
void		enemies_init(t_map *map);
void		enemy_chase_player(t_enemy *e, t_map *map, t_player *p);
void		enemy_move(t_player *p, t_map *map);
void		new_enemy(t_map *map, int x, int y);

// Initialization
void		set_player(t_player *p, int y, int x);
t_map		*map_init(t_map *map, t_player *p, t_vars *v);
t_vars		*vars_init(t_vars *v, t_map *map);
t_player	*player_init(t_player *player);
t_image		*img_init(t_image *img, char *relative_path, void *mlx);

// Validations
int			validate_ext(char *filename, char *suffix);
int			validate_tile(char c, t_map *map);
void		validate_map(t_map *map);

// Map parsing
t_map		*load_map(char *map_path, t_map *map);
void		read_map(char *map_path, t_map *map);

// Error handling
void		error_exit(int code, t_vars *vars);

// Game hooks
void		hooks(t_vars *v);

#endif