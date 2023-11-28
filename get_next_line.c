/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:42 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/28 15:52:53 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

#include <string.h>


char	*ft_get_line(char **str)
{
    int		i;
    char	*line;
    char	*tmp;

    i = 0;
    while ((*str)[i] != '\n' && (*str)[i] != '\0')
        i++;
    if ((*str)[i] == '\n')
    {
        line = ft_substr(*str, 0, i + 1);
        tmp = ft_strdup(&((*str)[i + 1]));
        free(*str);
        *str = tmp;
        if ((*str)[0] == '\0')
            ft_strdel(str);
    }
    else
    {
        line = ft_strdup(*str);
        ft_strdel(str);
    }
    return (line);
}


char	*find_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*start_newline;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || buffer[i] == '\0')
		return (free(buffer), NULL);
	if (buffer[i] == '\n')
		i++;
	start_newline = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (start_newline == NULL)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		start_newline[j++] = buffer[i++];
	start_newline[j++] = '\0';
	free(buffer);
	return (start_newline);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*tmp_buff;
	int		byte_read;

	byte_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (tmp_buff == NULL)
		return (NULL);
	while (byte_read > 0 && !ft_strchr(tmp_buff, '\n'))
	{
		byte_read = read(fd, tmp_buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(tmp_buff), free(buffer), NULL);
		tmp_buff[byte_read] = '\0';
		buffer = ft_strjoin(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	buffer = find_next_line(buffer);
	return (line);
}

char	*ft_strdup(char *src)
{
    char	*dest;
    int		i;

    i = 0;
    dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (dest == 0)
        return (0);
    while (src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
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