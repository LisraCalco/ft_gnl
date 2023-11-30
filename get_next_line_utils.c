/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:36 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/30 17:04:16 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

#include <stdlib.h>

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*ptr;

	ptr = malloc(element_count * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, element_count * element_size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char			*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
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
	free(tmp);
	return (line);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
		i++;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)string + i);
	return (0);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > (unsigned int)ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len >= (unsigned int) ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) *(len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
