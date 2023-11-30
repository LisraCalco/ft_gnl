/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:42 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/30 18:32:50 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

#include <string.h>


char	*ft_strdup(const char *source)
{
	char	*dest;
	int		i;

	i = 0;
	while (source[i])
		i++;
	dest = malloc(sizeof(char) *(i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strdel(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = 0;
    }
}

char	*read_buffer(int fd)
{
	char	*buffer;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (free(buffer), NULL);
	buffer[ret] = '\0';
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	while (buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
	static char	*tmp = NULL;
	char 		*buffer = NULL;
	char		*line = NULL;
	int			i;

	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (tmp != NULL)
	{
		while (tmp[i] != '\n' && tmp[i] != '\0')
			i++;

		if (tmp[0] == '\n')
		{
			line = ft_strdup("");
			char *tmp2 = ft_substr(tmp, 1, ft_strlen(tmp) - 1);
			if (tmp2 == NULL)
				return (NULL);
			free(tmp);
			tmp = tmp2;
			free(buffer);
			return (line);
		}
		else {
			if (tmp[i] == '\n')
			{
				line = ft_substr(tmp, 0, i);
				char *tmp2 = ft_substr(tmp, i + 1, ft_strlen(tmp) - i);
				free(tmp);
				tmp = tmp2;
				free(buffer);
				return (line);
			}
			else
			{
				line = ft_strdup(tmp);
				ft_strdel(&tmp);
			}
		}
	}
	else
	{
		free(line);
		line = ft_strdup("");
	}
	buffer = read_buffer(fd);
	while (buffer != NULL)
	{
		i = 0;
		if (buffer[0] == '\n') // check if the first character is a newline
		{
			free(line);
			line = malloc(2); // allocate memory for an empty string
			line[0] = '\n';
			line[1] = '\0'; 
			tmp = ft_substr(buffer, 1, ft_strlen(buffer) - 1); 
			free(buffer);
			return (line);
		}
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
		{
			char *tmpln = ft_strdup(line);
			free(line);
			line = ft_strjoin(tmpln, ft_substr(buffer, 0, i));
			free(tmp);
			tmp = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
			free(buffer);
			return (line);
		}
		else {

			line = ft_strjoin(line, buffer);
		}
		buffer = read_buffer(fd);
	}
	if (buffer == 0 && line[0] == '\0')
	{
		free(tmp);
		free(line);
		free(buffer);
		return (NULL);
	}
	if (buffer != NULL)
		free(buffer);
	return (line);
}
/*
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}*/