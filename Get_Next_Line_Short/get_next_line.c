/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:40:12 by ede-alme          #+#    #+#             */
/*   Updated: 2022/08/25 10:35:22 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	t_vars		var;

	line = NULL;
	while (1)
	{
		var.i = 0;
		var.j = 0;
		if (!buffer[0] && read(fd, buffer, BUFFER_SIZE) <= 0)
			return (line);
		line = ft_get_buff(line, buffer, var);
		while (var.i < BUFFER_SIZE && buffer[var.i] == '\0')
			var.i++;
		while (var.i < BUFFER_SIZE)
		{
			buffer[var.j++] = buffer[var.i];
			buffer[var.i++] = '\0';
		}
		var.i = 0;
		while (line && line[var.i])
			if (line[var.i++] == '\n')
				return (line);
	}
}

int	main(void)
{
	int		fd;
	char	*line;

	printf("BUFFERSIZE = %i\n", BUFFER_SIZE);
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
