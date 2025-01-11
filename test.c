#include <unistd.h>	// read; close;
#include <fcntl.h> 	// open;
#include <stdio.h>	// printf;

int	main()
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	// Open a file
	int	fd = open("file.txt", O_RDONLY); // Open file in Readonly
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
	return (0);
}