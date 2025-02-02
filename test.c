/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/29 19:45:11 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf;

int	main(void)
{
	char	*line;
	int		fd;

	printf("[Main] *** HELLO ***\n");
	printf("[Main] BUFFER_SIZE: '%d'\n", BUFFER_SIZE);
	fd = open("file_1lines.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file!");
		return (1);
	}
	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		printf("[Main] Line: '%s'\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		printf("[Main] Read of file finished!\n");
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}
	printf("[Main] *** BYE ***\n");
	return (0);
}
