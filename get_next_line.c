/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:09:43 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/13 16:45:13 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf; DELETE!!!

int	ft_letterpos(const char *str, int letter)
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
	if ((letter == EOF) && i != BUFFER_SIZE)
		return (i);
	return (-1);
}

char	*ft_set_line(char *line_buf)
{
	char	*line;
	int		pos_eol;
	int		pos_eof;
	int		pos;

	pos_eol = ft_letterpos(line_buf, (int) '\n');
	pos_eof = ft_letterpos(line_buf, (int) '\0');
	if (pos_eol >= 0)
		pos = pos_eol;
	else
		pos = pos_eof;
	line = ft_substr(line_buf, 0, pos);
	// free(line_buf);
	return (line);
}

char	*ft_fill_linebuf(int fd, char *line_buf, char *buffer)
{
	int	bytes_read;
	int	pos_eol;
	int	pos_eof;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		// perror("Error reading file!");
		return (NULL);
	}
	while (bytes_read != 0)
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
	}
	line_buf = ft_set_line(line_buf);
	// free(line_buf);
	return (line_buf);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;

	line = NULL;
	if (fd == -1)
	{
		// perror("Error opening file!");
		return (NULL);
	}
	if (BUFFER_SIZE < 1)
	{
		// perror("Buffer is too small!");
		return (NULL);
	}
	line = ft_fill_linebuf(fd, line, buffer);
	return (line);
}
