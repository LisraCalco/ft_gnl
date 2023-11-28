/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:36 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/28 15:57:24 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_calloc(int str_len, int size)
{
	char			*str;
	unsigned int	n;
	unsigned int	i;

	n = str_len * size;
	str = malloc(n);
	if (str == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *buffer, char *tmp)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc((ft_strlen(tmp) + ft_strlen(buffer) + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	while (buffer && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	while (tmp[j] != '\0')
	{
		line[i + j] = tmp[j];
		j++;
	}
	line[i + j] = '\0';
	free(buffer);
	return (line);
}

int	ft_strchr(char *buffer, int new_line_ptr)
{
	int	i;

	i = 0;
	if (buffer && buffer[i] == '\0')
		return (0);
	while (buffer && buffer[i] != '\0')
	{
		if (buffer[i] == new_line_ptr)
			return (1);
		i++;
	}
	return (0);
}


//ft_strcpy
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;

	if (src == 0)
		return (0);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, 1));
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == 0)
		return (0);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int     ft_strlen(const char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}