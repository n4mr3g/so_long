/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:25:56 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/21 23:39:10 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_exit(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	t_image	exit_img;

	if (vars->player->collected == map->collectibles)
		exit_img = img_init("images/exit_o.xpm", vars->mlx);
	else
		exit_img = img_init("images/exit_c.xpm", vars->mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, exit_img.img,
					x * TILESIZE, y * TILESIZE);
				return ;
			}
			y++;
		}
		x++;
	}
}
