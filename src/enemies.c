/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:02:29 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 13:16:45 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


void	enemies_init(t_map *map)
{
	int	i;

	i = 0;
	if (map->enemies == 0)
		return ;
	map->e_arr = malloc(sizeof(t_enemy) * map->enemies + 1);
	if (!map->e_arr)
		error_exit(12, map);
	while (i < map->enemies)
	{
		map->e_arr[i].x = 0;
		map->e_arr[i].y = 0;
		i++;
	}
}

void	draw_enemies(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	int		enemy_count;
	t_image	enemy_img;

	enemy_img = img_init("images/enemy2.xpm", vars->mlx);
	enemy_count = 0;
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->data[y][x] == 'X')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, enemy_img.img,
					x * TILESIZE, y * TILESIZE);
				map->e_arr[enemy_count].x = x;
				map->e_arr[enemy_count].y = y;
				if (++enemy_count == map->enemies)
					return ;
			}
			y++;
		}
		x++;
	}
}

void	enemy_chase_player(t_enemy e, t_map *map, t_player *p)
{
	if (e.x < p->x && map->data[e.y][e.x + 1] == '0')
	{
		map->data[e.y][e.x] = '0';
		e.x++;
	}
	else if (e.x > p->x && map->data[e.y][e.x - 1] == '0')
	{
		map->data[e.y][e.x] = '0';
		e.x--;
	}
	else if (e.y < p->y && map->data[e.y + 1][e.x] == '0')
	{
		map->data[e.y][e.x] = '0';
		e.y++;
	}
	else if (e.y > p->y && map->data[e.y - 1][e.x] == '0')
	{
		map->data[e.y][e.x] = '0';
		e.y--;
	}
	if (map->data[e.y][e.x] == 'P')
		ft_printf("You died!");
		// Lose condition
	else
		map->data[e.y][e.x] = 'X';
}

void	enemy_move(t_player *p, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->enemies)
	{
		enemy_chase_player(map->e_arr[i], map, p);
		i++;
	}
}
