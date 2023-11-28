/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:42 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/28 15:14:23 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

#include <string.h>



char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line;
    char *temp;
    char *rem_buf;
    int i;
    int j;

    i = 0;
    j = 0;
    rem_buf = 0;
    line = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
        
    if (buffer == NULL)
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buffer == NULL)
            return (0);
        buffer[BUFFER_SIZE] = '\0';
    }
    while (1)
    {
        if (buffer[i] == '\n')
        {
            line = malloc(sizeof(char) * (i + 1));
            if (line == NULL)
                return (0);
            line[i] = '\0';
            while (j < i)
            {
                line[j] = buffer[j];
                j++;
            }
            j = 0;
            while (buffer[i + 1 + j])
            {
                rem_buf = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
                if (rem_buf == NULL)
                    return (0);
                rem_buf[j] = buffer[i + 1 + j];
                j++;
            }
            rem_buf[j] = '\0';
            free(buffer);
            buffer = rem_buf;
            return (line);
        }
        if (buffer[i] == '\0')
        {
            temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
            if (temp == NULL)
                return (0);
            temp[BUFFER_SIZE] = '\0';
            read(fd, temp, BUFFER_SIZE);
            buffer = ft_strjoin(buffer, temp);
            free(temp);
            i = -1;
        }
        i++;
    }
    return (0);
}

