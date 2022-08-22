/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:25:54 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 01:39:40 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	validate_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->data[0][i] != '1' || map->data[map->height - 1][i] != '1')
			error_exit(11, NULL);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
			error_exit(11, map);
		i++;
	}
}

int	line_length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*line_dup(const char *s)
{
	int		i;
	char	*result;

	result = (char *)malloc(line_length(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	write_map(char *map_path, t_map *map)
{
	int		i;
	char	*buff;

	map->fd = open(map_path, O_RDONLY);
	map->data = malloc(sizeof(char *) * map->height);
	if (!map->data)
		error_exit(6, map);
	buff = get_next_line(map->fd);
	i = 0;
	while (buff)
	{
		map->data[i] = line_dup(buff);
		free(buff);
		buff = get_next_line(map->fd);
		i++;
	}
	free(buff);
	close(map->fd);
}

void	validate_map(t_map *map)
{
	if (map->width == map->height)
		error_exit(5, map);
	if (map->has_player < 1)
		error_exit(8, map);
	if (map->has_exit < 1)
		error_exit(9, map);
	if (map->collectibles == 0)
		error_exit(10, map);
	validate_map_walls(map);
}

void	draw_counters(t_map *map, t_vars *v)
{
	char	*gold_remaining;
	char	*moves;
	int		y;

	y = (map->height * TILESIZE) + (TILESIZE / 3);
	gold_remaining = ft_itoa(map->collectibles - v->player->collected);
	moves = ft_itoa(v->player->moves);
	if (!gold_remaining || !moves)
		error_exit(6, map);
	if (map->collectibles == v->player->collected)
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

void	draw_background(t_map *map, t_vars *v)
{
	int		i;
	t_image	img;

	i = 0;
	img = img_init("images/hud.xpm", v->mlx);
	while (i < map->width)
	{
		mlx_put_image_to_window(v->mlx, v->win, img.img, i * TILESIZE, map->height * TILESIZE);
		i++;
	}
}

void	draw_map(t_map *map, t_vars *vars)
{
	draw_floor(map, vars);
	draw_walls(map, vars);
	draw_collectibles(map, vars);
	draw_exit(map, vars);
	draw_player(map, vars);
	draw_enemies(map, vars);
	draw_background(map, vars);
	draw_counters(map, vars);
}

t_map	*load_map(char *map_path, t_map *map)
{
	map = malloc(sizeof(t_map));
	map_init(map);
	read_map(map_path, map);
	write_map(map_path, map);
	validate_map(map);
	enemies_init(map);
	return (map);
}

int	validate_tile(char c, t_map *map)
{
	if (c == 'E')
	{
		if (map->has_exit)
			error_exit(6, map);
		map->has_exit = 1;
	}
	else if (c == 'P')
	{
		if (map->has_player)
			error_exit(7, map);
		map->has_player = 1;
	}
	else if (c == 'C')
		map->collectibles++;
	else if (c == 'X')
		map->enemies++;
	else if (c != '0' && c != '1')
		error_exit(3, map);
	return (1);
}

// Reads map from map_path and validates data.
// Manages errors accordingly.
void	read_map(char *map_path, t_map *map)
{
	int		i;
	char	*buff;

	map->enemies = 0;
	map->fd = open(map_path, O_RDONLY);
	buff = get_next_line(map->fd);
	if (!buff)
		error_exit(2, NULL);
	map->width = line_length(buff);
	while (buff)
	{
		i = 0;
		while (buff[i] && buff[i] != '\n')
			validate_tile(buff[i++], map);
		if ((int)line_length(buff) != map->width)
			error_exit(4, buff);
		free(buff);
		buff = get_next_line(map->fd);
		map->height++;
	}
	free(buff);
	close(map->fd);
}
