/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 06:15:25 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 09:47:10 by gpiccion         ###   ########.fr       */
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

typedef struct s_map {
	t_player	*player;
	t_enemy		*e_arr;
	int			enemies;
	int			width;
	int			height;
	int			fd;
	int			has_player;
	int			has_exit;
	int			collectibles;
	char		**data;
}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}	t_vars;


// Player controller
void		move_up(t_player *p, t_map *map);
void		move_down(t_player *p, t_map *map);
void		move_left(t_player *p, t_map *map);
void		move_right(t_player *p, t_map *map);

void		enemy_chase_player(t_enemy e, t_map *map, t_player *p);
void		enemy_move(t_player *p, t_map *map);
void		enemies_init(t_map *map);
void		draw_enemies(t_map *map, t_vars *vars);
void		draw_floor(t_map *map, t_vars *vars);
void		draw_walls(t_map *map, t_vars *vars);
void		draw_player(t_map *map, t_vars *vars);
void		draw_exit(t_map *map, t_vars *vars);
void		draw_collectibles(t_map *map, t_vars *vars);
void		draw_wall(t_map *map, t_vars *vars, int x, int y);
void		draw_map(t_map *map, t_vars *vars);
void		map_init(t_map *map);
t_vars		vars_init(t_map *map);
void		player_init(t_player *player);
t_image		img_init(char *relative_path, void *mlx);
t_map		*load_map(char *map_path, t_map *map);
void		read_map(char *map_path, t_map *map);
void		error_exit(int code, void *vars);
void		print_error_msg(int code);
int			mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int			keyhook_funcs(int keycode, t_vars *vars);

#endif