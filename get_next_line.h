/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:11:00 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/12 21:27:53 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>	// For malloc; free; NULL;
# include <unistd.h>	// For read; close;
# include <fcntl.h>		// For open;
# include <stdio.h>		// For EOF;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif // BUFFER_SIZE

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_letterpos(const char *str, int letter);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif