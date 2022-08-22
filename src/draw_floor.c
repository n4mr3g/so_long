/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:06:50 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/21 23:39:29 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_floor(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	t_image	floor_img;

	floor_img = img_init("images/floor.xpm", vars->mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] != '1' && map->data[y][x] != 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, floor_img.img,
					x * TILESIZE, y * TILESIZE);
				// draw_floor(map, vars, x, y);
			y++;
		}
		x++;
	}
}
