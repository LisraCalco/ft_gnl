/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:42 by tlegendr          #+#    #+#             */
/*   Updated: 2023/12/02 00:11:40 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

char	*pull_data_from_file(int fd, int *ret)
{
	char	*buffer;

	*ret = -1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*ret = read(fd, buffer, BUFFER_SIZE);
	if (*ret == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*ret] = '\0';
	return (buffer);
}

char	*fetch_line(char **buffer)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	tmp = ft_substr(*buffer, i, ft_strlen(*buffer));
	if (!tmp)
		return (NULL);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = (*buffer)[i];
	free(*buffer);
	*buffer = tmp;
	return (line);
}

char	*prepare_gnl(int fd, char **buffer, int *ret)
{
	*ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!*buffer)
		*buffer = pull_data_from_file(fd, ret);
	if (!*buffer)
		return (NULL);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*tmp;
	int			ret;
	char		*line;

	if (prepare_gnl(fd, &buffer, &ret) == NULL)
		return (NULL);
	while (ft_strchr(buffer, '\n') == NULL && ret > 0)
	{
		tmp = pull_data_from_file(fd, &ret);
		if (ret > 0)
			buffer = ft_strjoin(buffer, tmp);
		free(tmp);
		if (!buffer)
			return (NULL);
	}
	line = fetch_line(&buffer);
	if (!line || line[0] == '\0' || ret == -1)
	{
		free(line);
		free(buffer);
		return (buffer = NULL, NULL);
	}
	return (line);
}

/*
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line = NULL;
	//int i = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
*/