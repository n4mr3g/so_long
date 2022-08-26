/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:39:59 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/25 22:24:54 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// Returns the length of a string until the first '\n' character found.
int	line_length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

// Like strdup, but copies an entire line.
// Allocates memory for the new string and returns it.
// Returns a pointer to the first character of the new string.
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
