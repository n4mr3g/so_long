/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:31:08 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 13:47:16 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Frees the memory allocated for the map (map->data).
void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height && map->data[i])
		free(map->data[i++]);
	free(map->data);
}

// Frees the pointers of the t_vars struct instance.
void	free_vars(t_vars *v)
{
	free(v->mlx);
	free(v->map->p);
	free(v->map);
	free(v);
}

// Closes the window according to the error code received as parameter.
// Calls the necessary functions to free the memory previously alllocated.
int	close_win(t_vars *vars, int error_code)
{
	if (error_code == 1)
	{
		exit(error_code);
		return (error_code);
	}
	else
		mlx_destroy_display(vars->mlx);
	if (error_code != 4 && error_code != 6
		&& error_code != 7)
		free_map_data(vars->map);
	free_vars(vars);
	exit(error_code);
	return (error_code);
}
