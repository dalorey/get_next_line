/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:09:43 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/28 17:41:24 by dlorenzo         ###   ########.fr       */
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

	if (!line_buf)
		return (NULL);
	pos_eol = ft_letterpos(line_buf, (int) '\n');
	if ((pos_eol < 0) || (pos_eol + 1 >= (int)ft_strlen(line_buf)))
		return (NULL);
	next_line_buf = ft_substr(line_buf, pos_eol + 1, ft_strlen(line_buf) - pos_eol - 1);
	next_line_buf[ft_strlen(next_line_buf)] = '\0';
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
	line = ft_substr(line_buf, 0, pos + 1);
	return (line);
}

static char	*ft_fill_line(int fd, char *line_buf, char *remainder)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;
	int		pos_eol;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (remainder)
	{
		line_buf = ft_strdup(remainder);
		// free (remainder);
		// remainder = NULL;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		// if (line_buf)
		// 	free (line_buf);
		free (buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	while (bytes_read > 0)
	{
		if (!line_buf)
			line_buf = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(line_buf, buffer);
			free (line_buf);
			line_buf = tmp;
		}
		pos_eol = ft_letterpos(buffer, (int) '\n');
		if ((pos_eol >= 0) || (ft_strlen(buffer) < BUFFER_SIZE))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	free (buffer);
	if (remainder)
		free (remainder);
	return (line_buf);
}

char	*get_next_line(int fd)
{
	char		*line_buf;
	static char	*remainder;
	char		*line;

	line_buf = NULL;
	line = NULL;
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
	// printf("[GNL] Line_buf: '%s' // Line: '%s' // Remainder: '%s'\n", line_buf, line, remainder);
	free (line_buf);
	line_buf = NULL;
	return (line);
}
