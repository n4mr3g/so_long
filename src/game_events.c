/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:43:18 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 21:48:59 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Frees allocated memory and exits the program.
int	game_over(t_vars *v)
{
	if (v->map->enemies > 0)
		free(v->map->e_arr);
	mlx_destroy_window(v->mlx, v->win);
	close_win(v, 0);
	return (0);
}

// Checks for possible winning or losing conditions.
// Closes the window if the player has lost or won.
void	win_check(t_vars *v, t_player *p, int y, int x)
{
	if (v->map->data[y][x] == 'E' && p->collected == v->map->collectibles)
	{
		ft_printf("%sYou won!%s\n", GREEN, C_RST);
		ft_printf("You made %s%d%s moves. Can you do better?\n",
			YELLOW, p->moves, C_RST);
		game_over(v);
	}
	else if (v->map->data[y][x] == 'X')
	{
		ft_printf("%sYou lost!%s\nTry again?\n", RED, C_RST);
		game_over(v);
	}
}

// keycode 65307 = escape key
// 119, 115, 97, 100 = w s a d, respectively.
int	keyhook_funcs(int keycode, t_vars *v)
{
	if (keycode == 65307)
		game_over(v);
	else if (keycode == 119)
		move_up(v);
	else if (keycode == 115)
		move_down(v);
	else if (keycode == 97)
		move_left(v);
	else if (keycode == 100)
		move_right(v);
	return (0);
}

// Hooks from mlx library.
void	hooks(t_vars *v)
{
	mlx_do_key_autorepeatoff(v->mlx);
	mlx_hook(v->win, 2, 1L << 0, keyhook_funcs, v);
	mlx_hook(v->win, 17, 0, game_over, v);
	mlx_loop(v->mlx);
}
