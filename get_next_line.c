/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:25:30 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/21 14:49:47 by helfayez         ###   ########.fr       */
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
	mallo = malloc(i + 1);
	if (!mallo)
	{
		free(mallo);
		return (NULL);
	}
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
		free(line);
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

char	*read_line(int fd, char *line, char *buffer)
{
	int		read_fa;
	char	*new_line;

	if (!buffer)
	{
		free(line);
		return (NULL);
	}
	read_fa = 1;
	while (!ft_strchr(line, '\n') && read_fa > 0)
	{
		read_fa = read(fd, buffer, BUFFER_SIZE);
		if (read_fa < 0)
			if (ft_free(line))
				return (NULL);
		buffer[read_fa] = '\0';
		new_line = ft_strjoin(l , buffer);
		if (!new_line)
			if (ft_free(line))
				return (NULL);
		free(line);
		line = new_line;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	line = read_line(fd, line, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	res = return_line(line);
	line = save_my_line(line);
	if (!res)
		if (ft_free(line))
			if (ft_free(res))
				return (NULL);
	return (res);
}

// #include <fcntl.h>     
// #include <unistd.h>    
// #include <stdio.h>      
// #include <stdlib.h>    

// #include "get_next_line.h" 

// int main(void)
// {
//     int     fd;
//     char    *line;

//    
//      fd = open("h.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }

//   
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);

// }
