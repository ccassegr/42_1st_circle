#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		result;
	char	*line;
	
	line = NULL;
	fd = 7;
	fd = open(av[1], O_RDONLY);
	result = 1;
	//if (fd == -1)
		//return (-1);
	while (result == 1)
	{
		result = get_next_line(fd, &line);
		printf("%d |>>| %s\n", result, line);
		free (line);
	}
	close(fd);
	return (0);
}