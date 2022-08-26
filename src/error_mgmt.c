/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:22:21 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/26 16:18:17 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Prints the "invalid character in map" error message and the correct usage.
void	invalid_char_msg(void)
{
	ft_printf("%sError (3)%s\nInvalid character found in map\n", RED, C_RST);
	ft_printf("Only the following characters are allowed for the map:\n");
	ft_printf("%s0%s for an empty space\n", YELLOW, C_RST);
	ft_printf("%s1%s for a wall\n", YELLOW, C_RST);
	ft_printf("%sC%s for a collectible\n", YELLOW, C_RST);
	ft_printf("%sE%s for a map exit\n", YELLOW, C_RST);
	ft_printf("%sP%s for the player's starting position\n", YELLOW, C_RST);
	ft_printf("%sX%s for enemies\n", YELLOW, C_RST);
}

// Prints the invalid arguments error message and the correct usage.
void	invalid_args_msg(void)
{
	ft_printf("%sError (1)%s\nInvalid arguments.\n", RED, C_RST);
	ft_printf("%sUsage:%s ./so_long [path to map].ber\n", YELLOW, C_RST);
}

// Receives an error code and prints the corresponding error message.
void	print_error_msg(int code)
{
	if (code == 1)
		invalid_args_msg();
	else if (code == 2)
		ft_printf("%sError (2)%s\nMap file could not be read.\n", RED, C_RST);
	else if (code == 3)
		invalid_char_msg();
	else if (code == 4)
		ft_printf("%sError (4)%s\nInconsistent line sizes in map.\n", RED, C_RST);
	else if (code == 5)
		ft_printf("%sError (5)%s\nMap not rectangular.\n", RED, C_RST);
	else if (code == 6)
		ft_printf("%sError (6)%s\nMap must have only one exit.\n", RED, C_RST);
	else if (code == 7)
		ft_printf("%sError (7)%s\nMap must have only one player\n", RED, C_RST);
	else if (code == 8)
		ft_printf("%sError (8)%s\nMap doesn't have a player.\n", RED, C_RST);
	else if (code == 9)
		ft_printf("%sError (9)%s\nMap doesn't have an exit.\n", RED, C_RST);
	else if (code == 10)
		ft_printf("%sError (10)%s\nNo collectibles found in map.\n", RED, C_RST);
	else if (code == 11)
		ft_printf("%sError (11)%s\nMap must be surrounded by walls.\n",
			RED, C_RST);
	else if (code == 12)
		ft_printf("%sError (12)%s\nFailed to allocate memory.\n", RED, C_RST);
}

// Prints the correct error message by calling print_error_msg(code).
// Exits the program by calling close_win(vars, code).
void	error_exit(int code, t_vars *vars)
{
	print_error_msg(code);
	close_win(vars, code);
}
