/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:25:30 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/15 16:54:59 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *line)
{
	int		i;
	int		j;
	char	*mallo;

	j = 0;
	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	mallo = NULL;//malloc(i + 1);
	if (!mallo)
		return (NULL);
	while (j < i)
	{
		mallo[j] = line[j];
		j++;
	}
	mallo[j] = '\0';
	return (mallo);
}

char	*c_save(size_t *i, char *line)
{
	if (!line)
		return (NULL);
	while (line[*i] && line[*i] != '\n')
		(*i)++;
	if (!line[*i])
	{
		return (NULL);
	}
	(*i)++;
	return (line);
}

char	*save_my_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*col_line;

	i = 0;
	j = 0;
	line = c_save(&i, line);
	if (!line)
		return (NULL);
	col_line = malloc(ft_strlen(line) - i + 1);
	if (!col_line)
	{
		free(line);
		return (NULL);
	}
	while (line[i + j])
	{
		col_line[j] = line[i + j];
		j++;
	}
	col_line[j] = '\0';
	free(line);
	return (col_line);
}

char	*read_line(int fd, char *line)
{
	int		read_fa;
	char	*new_line;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		if (ft_free(line))
			return (NULL);
	read_fa = 1;
	while (!ft_strchr(line, '\n') && read_fa > 0)
	{
		read_fa = read(fd, buffer, BUFFER_SIZE);
		if (read_fa < 0)
			if (ft_free(buffer))
				if (ft_free(line))
					return (NULL);
		buffer[read_fa] = '\0';
		new_line = ft_strjoin(line, buffer);
		free(line);
		line = new_line;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (!line)
		line = ft_strdup("");
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	res = return_line(line);
	if (!res)
		return (NULL);
	line = save_my_line(line);
	return (res);
}
