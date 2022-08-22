/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:32:51 by gpiccion          #+#    #+#             */
/*   Updated: 2022/08/21 03:01:50 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Allocates and returns a new string,
// which is the result of the concatenation of 's1' and 's2'. 
// Returns the new string, or NULL if the allocation fails. 
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char			*result;
	size_t			len1;
	size_t			len2;
	size_t			i;

	if (!s1)
		s1 = (char *)calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (*s2)
		result[i++] = *s2++;
	result[len1 + len2] = '\0';
	free(s1);
	return (result);
}

// Reads from file descriptor 'fd' (in iterations of BUFFER_SIZE) until finding
// a newline character or EOF.
// Returns the string read, or NULL if the file descriptor is closed or an error
// occurs.
char	*read_file(int fd, char *buff)
{
	char	*tmp;
	int		ret;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	ret = 1;
	while (!ft_strchr(buff, '\n') && ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[ret] = '\0';
		buff = ft_strjoin_gnl(buff, tmp);
	}
	free(tmp);
	return (buff);
}

// Reads the string 'buff' and returns the first line found.
char	*get_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff[0])
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// Reads the string 'buff' and returns the remaining string after the first line
char	*get_remain(char *buff)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		remain[j++] = buff[i++];
	remain[j] = '\0';
	free(buff);
	return (remain);
}

// Reads one line from the file descriptor 'fd' and returns it.
// Consequent calls to this function will return the next line
// from the file descriptor 'fd'.
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = get_line(buff);
	buff = get_remain(buff);
	return (line);
}
