/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:08:00 by ede-alme          #+#    #+#             */
/*   Updated: 2022/02/14 18:17:48 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	int			buff_size;
	char		*line;
	int			line_size;

	line_size = 0;
	line = NULL;
	buff_size = 0;
	while (1)
	{
		if (!buff[0])
			buff_size = read(fd, buff, BUFFER_SIZE);
		else
			buff_size = 1;
		line_size += get_size_linha(buff);
		if (buff_size > 0)
			line = ft_realoc(line, buff, line_size, &buff_size);
		if (buff_size <= 0)
			return (line);
	}
	return (line);
}

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("file1", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	close(fd1);
	close(fd2);
	return (0);
}

/*
	0; verificar parametros
	1:  //check buffer 
	{
		.1: New line in buffer
			get_line_from_buffr();
			return;
			
		.2 No line in buffer
			line = strdup(buffer);
			buffer = 0;
	}
	read_buffer = malloc(BUFFER_SIZE)
	while ()
	{
		read(fd, read_buffer, BUFFFR_SIZE):
		1. New line in	read_buffer
			get_line() buffer_return()
		2. No new line in read_buffer
			line += read_buffer;		
	}
*/
