/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:42 by tlegendr          #+#    #+#             */
/*   Updated: 2023/12/01 19:21:43 by tlegendr         ###   ########.fr       */
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

char *get_buffer_extract(int fd)
{
    char *tmp;
    int ret;
    char *buffer = NULL;
    ret = 1;
    if (!buffer)
        buffer = calloc((1), sizeof(char));
    tmp = calloc((BUFFER_SIZE + 1), sizeof(char));
    if (tmp == NULL)
    {
        free(buffer);
        return NULL;
    }
    while (ret > 0 && !ft_strchr(tmp, '\n'))
    {
        ret = read(fd, tmp, BUFFER_SIZE);
        if (ret == -1)
        {
            free(tmp);
            free(buffer);
            return NULL;
        }
        tmp[ret] = '\0';
        buffer = ft_strjoin(buffer, tmp);
    }
    free(tmp);
    return buffer;
}



char *extract_line_from_buffer(char **buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\0')
	{
		line = ft_strdup(*buffer);
		ft_strdel(buffer);
		return (line);
	}	
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = (*buffer)[j];
		j++;
	}
	line[j] = '\0';
	*buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer));
	return (line);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (buffer == NULL)
        buffer = get_buffer_extract(fd);
		if (buffer == NULL)
			return (NULL);
	//printf("bufferBefore = %s\n", buffer);
    line = extract_line_from_buffer(&buffer);
	//printf("bufferAfter = %s\n", buffer);
    if (line == NULL)
    {
        free(buffer);
        buffer = NULL;
    }

    return line;
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line = NULL;
	//int i = 0;
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}