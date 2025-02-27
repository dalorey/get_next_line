/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:09:49 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/26 13:46:05 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *remainder)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !remainder))
			return (free(buffer), free(remainder), NULL);
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(remainder, buffer);
			free(remainder);
			remainder = tmp;
		}
	}
	return (free(buffer), remainder);
}

static char	*ft_get_line(char *remainder)
{
	char	*line;
	int		pos;

	if (!remainder || !*remainder)
		return (NULL);
	pos = 0;
	while (remainder[pos] && remainder[pos] != '\n')
		pos++;
	line = ft_substr(remainder, 0, pos + 1);
	return (line);
}

static char	*ft_update_remainder(char *remainder)
{
	char	*new_rem;
	int		pos;

	if (!remainder)
		return (NULL);
	pos = 0;
	while (remainder[pos] && remainder[pos] != '\n')
		pos++;
	if (!remainder[pos])
		return (free(remainder), NULL);
	new_rem = ft_strdup(remainder + pos + 1);
	free(remainder);
	if (!new_rem || !*new_rem)
		return (free(new_rem), NULL);
	return (new_rem);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remainder = ft_read_line(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	remainder = ft_update_remainder(remainder);
	return (line);
}
