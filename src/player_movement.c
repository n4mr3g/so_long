/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:34:40 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/25 22:48:36 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Attempts to move the player in the given direction.
// Calls functions to check winning or losing condition,
// to move the enemies and to update the map.
void	player_move(t_vars *v, t_player *p, int y, int x)
{
	win_check(v, p, y, x);
	if (v->map->data[y][x] == '1' || v->map->data[y][x] == 'E')
		return ;
	if (v->map->data[y][x] == 'C')
		p->collected++;
	v->map->data[p->y][p->x] = '0';
	v->map->data[y][x] = 'P';
	p->moves++;
	set_player(p, y, x);
	enemy_move(p, v->map);
	draw_map(v->map, v, "CEPX0", 0);
}

void	move_up(t_vars *v)
{
	player_move(v, v->map->p, v->map->p->y - 1, v->map->p->x);
}

void	move_down(t_vars *v)
{
	player_move(v, v->map->p, v->map->p->y + 1, v->map->p->x);
}

void	move_left(t_vars *v)
{
	player_move(v, v->map->p, v->map->p->y, v->map->p->x - 1);
}

void	move_right(t_vars *v)
{
	player_move(v, v->map->p, v->map->p->y, v->map->p->x + 1);
}
