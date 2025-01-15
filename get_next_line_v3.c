/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:09:43 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/15 14:44:20 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf; getchar; DELETE!!!

static int	ft_letterpos(const char *str, int letter)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if ((int)str[i] == letter)
			return (i);
		i++;
	}
	if (letter == (int) '\0')
		return (ft_strlen(str));
	return (-1);
}

static char	*ft_set_remainder(char *line_buf)
{
	char	*next_line_buf;
	int		pos_eol;
	int		pos_eof;

	if (!line_buf)
		return (NULL);
	pos_eol = ft_letterpos(line_buf, (int) '\n');
	pos_eof = ft_letterpos(line_buf, (int) '\0');
	if (pos_eol < 0)
		return (NULL);
	next_line_buf = ft_substr(line_buf, pos_eol + 1, pos_eof - 1);
	return (next_line_buf);
}

static char	*ft_set_line(char *line_buf)
{
	char	*line;
	int		pos_eol;
	int		pos;

	if (!line_buf)
		return (NULL);
	pos_eol = ft_letterpos(line_buf, (int) '\n');
	if (pos_eol >= 0)
		pos = pos_eol;
	else
		pos = ft_strlen(line_buf);
	line = ft_substr(line_buf, 0, pos);
	return (line);
}

static char	*ft_fill_line(int fd, char *line_buf, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		pos_eol;
	int		pos_eof;

	if (remainder)
	{
		line_buf = ft_strdup(remainder);
		free (remainder);
		remainder = NULL;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read == 0)
	{
		buffer[bytes_read] = '\0';
		// return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!line_buf)
			line_buf = ft_strdup(buffer);
		else
			line_buf = ft_strjoin(line_buf, buffer);
		pos_eol = ft_letterpos(buffer, (int) '\n');
		pos_eof = ft_letterpos(buffer, (int) '\0');
		if ((pos_eol >= 0) || (pos_eof >= 0))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			buffer[0] = '\0';
			return (NULL);
		}
	}
	return (line_buf);
}

char	*get_next_line(int fd)
{
	char		*line_buf;
	static char	*remainder;
	char		*line;

	// printf("[get_next_line] *** HELLO ***\n");
	line_buf = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		// perror("Buffer is too small!");
		return (NULL);
	}
	line_buf = ft_fill_line(fd, line_buf, remainder);
	if (!line_buf)
		return (NULL);
	line = ft_set_line(line_buf);
	remainder = ft_set_remainder(line_buf);
	// printf("[get_next_line] line_buf: '%s'\n", line_buf);
	// printf("[get_next_line] remainder: '%s'\n", remainder);
	// printf("[get_next_line] line: '%s'\n", line);
	free (line_buf);
	return (line);
}
