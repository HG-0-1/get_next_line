/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:24:37 by helfayez          #+#    #+#             */
/*   Updated: 2025/09/16 17:16:57 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mallo;
	size_t	lenss;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	lenss = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	mallo = malloc(lenss * sizeof(char) + 1);
	if (!mallo)
		return (NULL);
	while (s1[i] != 0)
	{
		mallo[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		mallo[i++] = s2[j];
		j++;
	}
	mallo[i] = '\0';
	return (mallo);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*mallo;

	i = 0;
	mallo = (char *)malloc((sizeof(char) * ft_strlen(s) + 1));
	if (!mallo)
		return (NULL);
	while (s[i] != '\0')
	{
		mallo[i] = s[i];
		i++;
	}
	mallo[i] = '\0';
	return (mallo);
}

int	ft_free(void *ptr2)
{
	free(ptr2);
	return (1);
}
