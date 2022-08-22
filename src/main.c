/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 06:13:49 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 13:44:03 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// keycode 65307 = escape key
int	close_win(t_vars *vars)
{
	free(vars->player);
	free(vars->map->e_arr);
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

// keycode 65307 = escape key
// 119, 115, 97, 100 = w s a d, respectively
int	keyhook_funcs(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		//error_exit(0, vars);
		close_win(vars);
	else if (keycode == 119)
		move_up(vars->player, vars->map);
	else if (keycode == 115)
		move_down(vars->player, vars->map);
	else if (keycode == 97)
		move_left(vars->player, vars->map);
	else if (keycode == 100)
		move_right(vars->player, vars->map);
	else
		ft_printf("%d\n", keycode);
	draw_map(vars->map, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*game_map;
	t_player	*player;
	t_vars		*vars;

	if (argc != 2)
		error_exit(1, NULL);
	game_map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	vars = malloc(sizeof(t_vars));
	player_init(player);
	game_map = load_map(argv[1], game_map);
	vars->map = game_map;
	vars->player = player;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, game_map->width * TILESIZE,
			(game_map->height + 1) * TILESIZE, "so_long");
	draw_map(vars->map, vars);
	mlx_hook(vars->win, 2, 1L << 0, keyhook_funcs, vars);
	mlx_loop(vars->mlx);
	return (0);
}
