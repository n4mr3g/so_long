/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:02:29 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 13:07:07 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Allocates memory for the array of enemies (map->e_arr)
// according to the counter "map->enemies",
// and initializes each enemie's 'x' and 'y' values.
void	enemies_init(t_map *map)
{
	int	i;

	i = 0;
	if (map->enemies == 0)
		return ;
	map->e_arr = (t_enemy *)malloc(sizeof(t_enemy) * map->enemies);
	if (!map->e_arr)
		error_exit(12, map->v);
	while (i < map->enemies)
	{
		map->e_arr[i].x = 0;
		map->e_arr[i].y = 0;
		i++;
	}
}

// Called in draw_tiles_c() each time an 'X' is found in the map.
// Sets the x and y coordinates of the enemy found.
void	new_enemy(t_map *map, int y, int x)
{
	static int	i = 0;

	map->e_arr[i].x = x;
	map->e_arr[i].y = y;
	i++;
}

// Called by enemy_move() for each existing enemy.
// Moves an enemy one position towards the player, if possible.
void	enemy_chase_player(t_enemy *e, t_map *map, t_player *p)
{
	if (e->x < p->x && map->data[e->y][e->x + 1] == '0')
	{
		map->data[e->y][e->x] = '0';
		e->x++;
	}
	else if (e->x > p->x && map->data[e->y][e->x - 1] == '0')
	{
		map->data[e->y][e->x] = '0';
		e->x--;
	}
	else if (e->y < p->y && map->data[e->y + 1][e->x] == '0')
	{
		map->data[e->y][e->x] = '0';
		e->y++;
	}
	else if (e->y > p->y && map->data[e->y - 1][e->x] == '0')
	{
		map->data[e->y][e->x] = '0';
		e->y--;
	}
	map->data[e->y][e->x] = 'X';
}

// Calls enemy_chase_player() for each existing enemy in the array of enemies.
void	enemy_move(t_player *p, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->enemies)
	{
		enemy_chase_player(map->e_arr + i, map, p);
		i++;
	}
}
