/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:29:14 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 00:07:42 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	player_init(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->moves = 0;
	player->collected = 0;
}

void	map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->fd = 0;
	map->has_player = 0;
	map->has_exit = 0;
	map->collectibles = 0;
	map->data = NULL;
}

t_image	img_init(char *relative_path, void *mlx)
{
	t_image	this;

	this.relative_path = relative_path;
	this.mlx = mlx;
	this.img = mlx_xpm_file_to_image(this.mlx, this.relative_path,
			&this.width, &this.height);
	return (this);
}

/* t_vars	vars_init(t_map *map)
{
	t_vars	*this;

	this->mlx = mlx_init();
	this->map = map;
	this->player = player;
	return (this);
}
 */