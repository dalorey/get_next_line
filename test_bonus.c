/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/28 21:32:00 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf;
#include <fcntl.h>	// For open;

int	main(void)
{
	char	*line1;
	int		fd1;
	char	*line2;
	int		fd2;

	printf("[Main] BUFFER_SIZE: '%d'\n", BUFFER_SIZE);
	fd1 = open("file_2lines.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	while (line1 != NULL)
	{
		printf("[Main] Line f1: '%s'\n", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
	fd2 = open("file_3lines.txt", O_RDONLY);
	line2 = get_next_line(fd2);
	while (line2 != NULL)
	{
		printf("[Main] Line f2: '%s'\n", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	printf("[Main] Read of file finished!\n");
	return (close (fd1), close (fd2), 0);
}
