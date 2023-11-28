/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:36 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/28 14:04:08 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
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

char *ft_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (dest == 0)
        return (0);
    ft_strcpy(dest, src);
    return (dest);
}

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)s + i);
        i++;
    }
    if (s[i] == c)
        return ((char *)s + i);
    return (0);
}