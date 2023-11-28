/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:45 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/28 15:57:01 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>


char    *get_next_line(int fd);
char	*ft_strjoin(char *buffer, char *tmp);
int     ft_strlen(const char *string);
char	*ft_strcpy(char *dest, char *src);
int	    ft_strchr(char *buffer, int new_line_ptr);
void	*ft_calloc(int str_len, int size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **str);

#endif