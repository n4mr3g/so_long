/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:23:29 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/21 23:39:29 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_collectibles(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	t_image	coll_img;

	coll_img = img_init("images/gold.xpm", vars->mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, coll_img.img,
					x * TILESIZE, y * TILESIZE);
			y++;
		}
		x++;
	}
}
