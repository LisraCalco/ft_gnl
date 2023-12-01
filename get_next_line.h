/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:45 by tlegendr          #+#    #+#             */
/*   Updated: 2023/12/01 18:44:46 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char    *get_next_line(int fd);
char	*ft_strjoin(char *buffer, char *tmp);
int     ft_strlen(const char *string);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_calloc(int str_len, int size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **str);

#endif