/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:28:58 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/21 23:39:29 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_player(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	t_image	player_img;

	player_img = img_init("images/player.xpm", vars->mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, player_img.img,
					x * TILESIZE, y * TILESIZE);
				vars->player->x = x;
				vars->player->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
