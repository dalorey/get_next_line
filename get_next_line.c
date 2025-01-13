/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:09:43 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/13 07:12:15 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf; DELETE!!!

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*current_line;
	static char	*next_line;
	ssize_t		bytes_read;
	int			pos_eol;
	int			pos_eof;

	// printf("\n[get_next_line] +++ HELLO +++\n");
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	// printf("[get_next_line] bytes_read: %ld\n", bytes_read);
	// printf("[get_next_line] sizeof(buffer): %ld\n", sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
		return(NULL);
	printf("[get_next_line] Buffer content:\n%s\n", buffer);
	pos_eol = ft_letterpos(buffer, 10);
	printf("[get_next_line] EOL pos: %d\n", pos_eol);
	pos_eof = ft_letterpos(buffer, (int)EOF);
	printf("[get_next_line] EOF pos: %d\n", pos_eof);
	if (pos_eol >= 0)
	{
		// printf("Buffer contains EOL\n");
		next_line = ft_substr(buffer, (size_t)pos_eol + 1, (size_t)pos_eof - pos_eol - 1);
		// printf("[EOL] Next line: \n%s\n", next_line);
		current_line = ft_substr(buffer, 0, (size_t)pos_eol);
		printf("[EOL] Current line: \n%s\n", current_line);
		printf("[EOL] --- BYE ---\n\n");
		return (current_line);
	}
	else if ((pos_eol < 0) && (pos_eof) < 0)
	{
		// printf("Buffer does not contain EOL or EOF\n");
		// Concatenate Buffer & call again get_next_line
		ft_strjoin(next_line, buffer);
		current_line = get_next_line(fd);
	}
	else if (pos_eof >= 0)
	{
		printf("[get_next_line] Buffer contains EOF\n");
		printf("[get_next_line] Buffer content: \n%s\n", buffer);
		printf("[get_next_line] Current line content: \n%s\n", current_line);
		printf("[get_next_line] Next line content: \n%s\n", next_line);
		// Concatenate Buffer & return current line;
		current_line = ft_strjoin(current_line, buffer);
		printf("[get_next_line] Buffer content: \n%s\n", buffer);
		printf("[get_next_line] Current line content: \n%s\n", current_line);
		printf("[get_next_line] Next line content: \n%s\n", next_line);
		// printf("[EOF] --- BYE ---\n\n");
		return (current_line);
	}
	// line = ft_strdup(buffer);
	// printf("[get_next_line] Line content: \n%s\n", line);
	// printf("[get_next_line] --- BYE ---\n\n");
	return (current_line);
}
