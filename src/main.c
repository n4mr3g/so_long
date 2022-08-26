/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 06:13:49 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 16:02:19 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
For running on a WSL environment:

We need to install a Windows X host like VcXsrv in order to run this game.

You can get VcXsrv here:
https://sourceforge.net/projects/vcxsrv/

Also, in our Linux subsystem, we need to set the "DISPLAY" environment variable
with the IP address of the Window X host.

This is because WSL doesn't include a graphics interface.
We can do so by simply running this command in the terminal:

--------------------------------------------------------------------------------
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
--------------------------------------------------------------------------------

If we don't do this, a segmentation fault will occur when trying to run the game.
*/
int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;
	t_vars		*vars;

	if (argc != 2 || validate_ext(argv[1], ".ber"))
		error_exit(1, NULL);
	map = (t_map *)malloc(sizeof(t_map));
	player = (t_player *)malloc(sizeof(t_player));
	vars = (t_vars *)malloc(sizeof(t_vars));
	player = player_init(player);
	map = map_init(map, player, vars);
	vars = vars_init(vars, map);
	map = load_map(argv[1], map);
	vars->win = mlx_new_window(vars->mlx, map->width * TILESIZE,
			(map->height + 1) * TILESIZE, "so_long");
	draw_map(map, vars, "CEPX01", 1);
	hooks(vars);
	return (0);
}
