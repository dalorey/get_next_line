/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:26:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/13 07:02:00 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	// For printf;

int	main(void)
{
	char	*line;
	int		fd;
	// static char		buffer[BUFFER_SIZE];
	// ssize_t		bytes_read;
/*
	// Open a file
	fd = open("file.txt", O_RDONLY); // Open file in Readonly
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(fd);
		return (1);
	}
	buffer[bytes_read] = '\0'; // End of string
	printf("File content:\n%s\n\n", buffer);
	close(fd);
*/
/*
	// Read from keyboard
	printf("Insert text: \n");
	bytes_read = read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		perror("Error reading from keyboard");
		return (1);
	}
	buffer[bytes_read] = '\0';
	printf("Text typed:\n%s\n", buffer);
*/
	printf("[Main] *** HELLO ***\n");
	printf("[Main] BUFFER_SIZE: %d\n", BUFFER_SIZE);
	fd = open("file_1lines.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("[Main] Line: \n%s\n", line);
	printf("[Main] *** BYE ***\n");
	return (0);
}
