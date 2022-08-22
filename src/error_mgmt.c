/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:22:21 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/22 13:39:31 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
Code 1: Invalid arguments.
Code 2: Error loading map.
*/

void	invalid_char_msg(void)
{
	ft_printf("%sError:%s Invalid character found in map.\n", RED, C_RST);
	ft_printf("Only the following characters are allowed for the map:\n");
	ft_printf("%s0%s for an empty space.\n", YELLOW, C_RST);
	ft_printf("%s1%s for a wall.\n", YELLOW, C_RST);
	ft_printf("%sC%s for a collectible.\n", YELLOW, C_RST);
	ft_printf("%sE%s for a map exit.\n", YELLOW, C_RST);
	ft_printf("%sP%s for the player's starting position.\n", YELLOW, C_RST);
}

void	invalid_args_msg(void)
{
	ft_printf("%sError:%s Invalid arguments.\n", RED, C_RST);
	ft_printf("Usage: ./so_long [map_path]\n");
}

void	print_error_msg(int code)
{
	if (code == 1)
		invalid_char_msg();
	else if (code == 2)
		ft_printf("%sError%s\n Map file could not be read.\n", RED, C_RST);
	else if (code == 3)
		invalid_char_msg();
	else if (code == 4)
		ft_printf("%sError%s\n Map has inconsistent line sizes.\n",
			RED, C_RST);
	else if (code == 5)
		ft_printf("%sError%s\n Map is square, but must be rectangular.\n",
			RED, C_RST);
	else if (code == 6)
		ft_printf("%sError%s\n Map must contain only one exit.\n", RED, C_RST);
	else if (code == 7)
		ft_printf("%sError%s\n Map must contain only one player.\n", RED, C_RST);
	else if (code == 8)
		ft_printf("%sError%s\n Map doesn't contain a player.\n", RED, C_RST);
	else if (code == 9)
		ft_printf("%sError%s\n Map doesn't contain an exit.\n", RED, C_RST);
	else if (code == 10)
		ft_printf("%sError%s\n Map doesn't contain any collectibles.\n",
			RED, C_RST);
	else if (code == 11)
		ft_printf("%sError%s\n Map must be surrounded by walls.\n", RED, C_RST);
}

void	error_exit(int code, void *vars)
{
	print_error_msg(code);
	if (vars)
		free(vars);
	exit(code);
}
