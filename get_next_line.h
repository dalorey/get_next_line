/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:11:00 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:23 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>	// For malloc; free; NULL;
# include <unistd.h>	// For read; close;
# include <fcntl.h>		// For open;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif // BUFFER_SIZE

char	*get_next_line(int fd);
char	*ft_strchr(const char *src, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif