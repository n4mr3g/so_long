/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:41:55 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 16:22:57 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Receives a character and returns the t_image corresponding to that tile type.
t_image	*char_to_img(char c, t_vars *v)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (c == 'P')
		img = img_init(img, "images/player.xpm", v->mlx);
	else if (c == 'C')
		img = img_init(img, "images/gold.xpm", v->mlx);
	else if (c == '1')
		img = img_init(img, "images/wall.xpm", v->mlx);
	else if (c == '0')
		img = img_init(img, "images/floor.xpm", v->mlx);
	else if (c == 'X')
		img = img_init(img, "images/enemy.xpm", v->mlx);
	else if (c == 'B')
		img = img_init(img, "images/hud.xpm", v->mlx);
	else if (c == 'E' && v->map->p->collected == v->map->collectibles)
		img = img_init(img, "images/exit_o.xpm", v->mlx);
	else if (c == 'E')
		img = img_init(img, "images/exit_c.xpm", v->mlx);
	return (img);
}

// Runs through the map array looking for the character in the third argument.
// Each time it finds it, it puts the corresponding image on the window.
// The fourth
void	draw_tiles_c(t_map *map, t_vars *vars, char c, int first_time)
{
	int		x;
	int		y;
	t_image	*img;

	img = char_to_img(c, vars);
	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			if (map->data[y][x] == c)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, img->img,
					x * TILESIZE, y * TILESIZE);
				if (c == 'P' && first_time)
					set_player(map->p, y, x);
				else if (c == 'X' && first_time)
					new_enemy(map, y, x);
			}
		}
	}
	mlx_destroy_image(vars->mlx, img->img);
	free(img);
}

// Draws the movement counter and the collectibles remaining counter.
void	draw_counters(t_map *map, t_vars *v)
{
	char	*gold_remaining;
	char	*moves;
	int		y;

	y = (map->height * TILESIZE) + (TILESIZE / 3);
	gold_remaining = ft_itoa(map->collectibles - v->map->p->collected);
	moves = ft_itoa(v->map->p->moves);
	if (!gold_remaining || !moves)
		error_exit(6, v);
	if (map->collectibles == v->map->p->collected)
		mlx_string_put(v->mlx, v->win, 10, y, 0x00FF00,
			"All gold collected, exit now!");
	else
	{
		mlx_string_put(v->mlx, v->win, 10, y, 0x00FFFFFF, "Gold remaining:");
		mlx_string_put(v->mlx, v->win, 150, y, 0x00FFFFFF, gold_remaining);
	}	
	mlx_string_put(v->mlx, v->win, 10, y + (TILESIZE / 3),
		0x00FFFFFF, "Moves:");
	mlx_string_put(v->mlx, v->win, 150, y + (TILESIZE / 3), 0x00FFFFFF, moves);
	free(gold_remaining);
	free(moves);
}

// Draws the background of the movement and collectibles counters.
void	draw_background(t_map *map, t_vars *v)
{
	int		i;
	t_image	*img;

	i = -1;
	img = char_to_img('B', v);
	while (++i < map->width)
		mlx_put_image_to_window(v->mlx, v->win, img->img,
			i * TILESIZE, map->height * TILESIZE);
	mlx_destroy_image(v->mlx, img->img);
	free(img);
}

// Main function for drawing the map,
// including the movement and collectibles counters.
void	draw_map(t_map *map, t_vars *vars, char *tiles, int first_time)
{
	int		i;

	i = -1;
	while (tiles[++i])
		draw_tiles_c(map, vars, tiles[i], first_time);
	draw_background(map, vars);
	draw_counters(map, vars);
}
