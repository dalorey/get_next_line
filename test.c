/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/28 20:12:17 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf;
#include <fcntl.h>	// For open;

int	main(void)
{
	char	*line;
	int		fd;

	printf("[Main] *** HELLO ***\n");
	printf("[Main] BUFFER_SIZE: '%d'\n", BUFFER_SIZE);
	fd = open("file_longlines.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("[Main] Line: '%s'\n", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("[Main] Read of file finished!\n");
	if (close(fd) == -1)
		return (perror("Error closing file"), 1);
	printf("[Main] *** BYE ***\n");
	return (0);
}
