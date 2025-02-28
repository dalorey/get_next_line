/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:09:49 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/28 20:40:54 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h> // For printf -- Delete!!!
/*
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
*/
static char	*ft_read_line(int fd, char *draft_line)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(draft_line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(draft_line), NULL);
		buffer[bytes_read] = '\0';
		if (!draft_line)
			draft_line = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(draft_line, buffer);
			free(draft_line);
			draft_line = temp;
		}
	}
	return (free(buffer), draft_line);
}

static char	*ft_clean_line(const char *draft_line)
{
	char	*line;
	size_t	i;

	if (!draft_line || !*draft_line)
		return (NULL);
	i = 0;
	while (draft_line[i] && draft_line[i] != '\n')
		i++;
	line = ft_substr(draft_line, 0, i + 1);
	return (line);
}

static char	*ft_update_draft(char *draft)
{
	char	*new_draft;
	int		pos;

	if (!draft)
		return (NULL);
	pos = 0;
	while (draft[pos] && draft[pos] != '\n')
		pos++;
	if (!draft[pos])
		return (free(draft), NULL);
	new_draft = ft_substr(draft, pos + 1, ft_strlen(draft) - pos - 1);
	free (draft);
	if (!new_draft || !*new_draft)
		return (free(new_draft), NULL);
	return (new_draft);
}

char	*get_next_line(int fd)
{
	static char	*draft_line[MAX_FD];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= MAX_FD)
		return (NULL);
	draft_line[fd] = ft_read_line(fd, draft_line[fd]);
	line = ft_clean_line(draft_line[fd]);
	draft_line[fd] = ft_update_draft(draft_line[fd]);
	return (line);
}
