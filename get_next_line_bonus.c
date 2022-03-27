/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:03:17 by ede-alme          #+#    #+#             */
/*   Updated: 2022/02/14 19:06:53 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE];
	int			buff_size;
	char		*line;
	int			line_size;

	line_size = 0;
	line = NULL;
	buff_size = 0;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (!buff[fd][0])
			buff_size = read(fd, buff[fd], BUFFER_SIZE);
		else
			buff_size = 1;
		line_size += get_size_linha(buff[fd]);
		if (buff_size > 0)
			line = ft_realoc(line, buff[fd], line_size, &buff_size);
		if (buff_size <= 0)
			return (line);
	}
	return (line);
}
/*
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
*/
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
