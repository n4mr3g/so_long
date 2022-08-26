/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:37:21 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 16:16:32 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Checks if the received string ends with the given suffix.
// Returns 1 if it does, 0 otherwise.
int	validate_ext(char *filename, char *suffix)
{
	int	f_len;
	int	s_len;
	int	is_different;

	f_len = ft_strlen(filename);
	s_len = ft_strlen(suffix);
	if (f_len <= s_len)
		return (1);
	is_different = ft_strncmp(filename + f_len - s_len, suffix, s_len);
	return (is_different);
}

// Checks if the map is surrounded by walls.
void	validate_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->data[0][i] != '1' || map->data[map->height - 1][i] != '1')
			error_exit(11, map->v);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
			error_exit(11, map->v);
		i++;
	}
}

// Checks if the map complies with the following rules:
// - The map must be rectangular.
// - The map must have at least one '1' collectible.
// - The map must have only one player.
// - The map must have only one exit.
// - The map must be surrounded by walls (calls validate_map_walls).
void	validate_map(t_map *map)
{
	if (map->width == map->height)
		error_exit(5, map->v);
	if (map->has_player < 1)
		error_exit(8, map->v);
	if (map->has_exit < 1)
		error_exit(9, map->v);
	if (map->collectibles == 0)
		error_exit(10, map->v);
	validate_map_walls(map);
}

// Checks if the character 'c' is a valid tile for the map.
// In case it's X or C, increments the respective counter.
// In case it's P, or E, sets has_player or has_exit to 1, respectively.
// Returns an integer error code if the character is not valid.
int	validate_tile(char c, t_map *map)
{
	if (c == 'E')
	{
		if (map->has_exit)
			return (6);
		map->has_exit = 1;
	}
	else if (c == 'P')
	{
		if (map->has_player)
			return (7);
		map->has_player = 1;
	}
	else if (c == 'C')
		map->collectibles++;
	else if (c == 'X')
		map->enemies++;
	else if (c != '0' && c != '1')
		return (3);
	return (0);
}
