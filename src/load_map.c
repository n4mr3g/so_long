/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:25:54 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 01:42:24 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Saves the map in memory through the use of get_next_line().
void	write_map(char *map_path, t_map *map)
{
	int		i;
	char	*buff;

	map->fd = open(map_path, O_RDONLY);
	map->data = malloc(sizeof(char *) * map->height);
	if (!map->data)
		error_exit(6, map->v);
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

// Loads the map from *map_math into the struct *map.
// Also validates it and initializes the enemies.
t_map	*load_map(char *map_path, t_map *map)
{
	read_map(map_path, map);
	write_map(map_path, map);
	validate_map(map);
	enemies_init(map);
	return (map);
}

// Reads the buffer gotten from get_next_line and validates it
// with validate_tile().
int	read_buff(char *buff, t_map *map)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (!error)
			error = validate_tile(buff[i], map);
		i++;
	}
	if (!error && (int)line_length(buff) != map->width)
		error = 4;
	free(buff);
	if (!error)
		map->height++;
	return (error);
}

// Reads map from map_path and validates data.
// Manages errors accordingly.
void	read_map(char *map_path, t_map *map)
{
	char	*buff;
	int		error;

	error = 0;
	map->fd = open(map_path, O_RDONLY);
	buff = get_next_line(map->fd);
	if (!buff)
		error_exit(2, map->v);
	map->width = line_length(buff);
	while (buff)
	{
		if (!error)
			error = read_buff(buff, map);
		else
			free(buff);
		buff = get_next_line(map->fd);
	}
	close(map->fd);
	if (!error)
		return ;
	free(buff);
	error_exit(error, map->v);
}
