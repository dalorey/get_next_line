/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/13 16:39:48 by dlorenzo         ###   ########.fr       */
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
	fd = open("file_3lines.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("[Main] Line: '%s'\n", line);
		printf("[Main] *** BYE ***\n");
		free(line);
		line = get_next_line(fd);
	}
	// free(line);
	return (0);
}
