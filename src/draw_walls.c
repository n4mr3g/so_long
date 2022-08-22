/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:25:43 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 01:09:28 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	draw_walls(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	t_image	wall_img;

	wall_img = img_init("images/wall.xpm", vars->mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, wall_img.img, x * TILESIZE, y * TILESIZE);
			y++;
		}
		x++;
	}
}

/* void	draw_wall(t_map *map, t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, wall_img->img, x * TILESIZE, y * TILESIZE);
} */
