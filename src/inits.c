/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:29:14 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 13:52:00 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Sets new values to the player's 'x' and 'y' position values.
void	set_player(t_player *p, int y, int x)
{
	p->x = x;
	p->y = y;
}

// Initializes the player struct's values.
t_player	*player_init(t_player *player)
{
	set_player(player, 0, 0);
	player->moves = 0;
	player->collected = 0;
	return (player);
}

// Initializes the map struct's values.
t_map	*map_init(t_map *map, t_player *p, t_vars *v)
{
	map->p = p;
	map->v = v;
	map->width = 0;
	map->height = 0;
	map->fd = 0;
	map->has_player = 0;
	map->has_exit = 0;
	map->collectibles = 0;
	map->enemies = 0;
	map->e_arr = NULL;
	map->data = NULL;
	return (map);
}

t_image	*img_init(t_image *img, char *relative_path, void *mlx)
{
	img->relative_path = relative_path;
	img->mlx = mlx;
	img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path,
			&img->width, &img->height);
	return (img);
}

// Initializes the values of the t_vars struct,
// assigning to it the t_map pointer received as second argument.
// Calls mlx_init() to initialize the mlx variable.
t_vars	*vars_init(t_vars *v, t_map *map)
{
	v->map = map;
	v->mlx = mlx_init();
	return (v);
}
