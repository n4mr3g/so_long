/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:43:18 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 13:24:00 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	win_check(t_map *map, t_player *p, int y, int x)
{
	if (map->data[y][x] == 'E' && p->collected == map->collectibles)
	{
		//mlx_destroy_window(map->vars.mlx, map->vars.win);
		ft_printf("You win!\n");
		exit(0);
	}
	else if (map->data[y][x] == 'X')
	{
		ft_printf("You lose!\n");
		exit(0);
	}
}

void	player_move(t_map *map, t_player *p, int y, int x)
{
	if (map->data[y][x] != '1')
	{
		if (map->data[y][x] == 'C')
			p->collected++;
		map->data[p->y][p->x] = '0';
		p->y = y;
		p->x = x;
		p->moves++;
		win_check(map, p, y, x);
		map->data[y][x] = 'P';
		enemy_move(p, map);
	}
}

void	move_up(t_player *p, t_map *map)
{
	player_move(map, p, p->y - 1, p->x);
}

void	move_down(t_player *p, t_map *map)
{
	player_move(map, p, p->y + 1, p->x);
}

void	move_left(t_player *p, t_map *map)
{
	player_move(map, p, p->y, p->x - 1);
}

void	move_right(t_player *p, t_map *map)
{
	player_move(map, p, p->y, p->x + 1);
}
