/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/15 14:42:01 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf;

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	printf("[Main] *** HELLO ***\n");
	printf("[Main] BUFFER_SIZE: '%d'\n", BUFFER_SIZE);
	fd = open("file_longlines.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file!");
		return (1);
	}
	i = 1;
	// printf("[Main] call #%d\n", i);
	line = get_next_line(fd);
	printf("[Main] Line: '%s'\n", line);
	if (!line)
		printf("[Check] No line available to read!\n");
	while (line != NULL)
	{
		free(line);
		i++;
		// printf("[Main] call #%d\n", i);
		line = get_next_line(fd);
		printf("[Main] Line: '%s'\n", line);
	}
	if (close(fd) == -1)
	{
		perror("[Check] Error closing file");
		return (1);
	}
	// printf("[Main] # of calls to get next line: %d\n", i);
	printf("[Main] *** BYE ***\n");
	return (0);
}

