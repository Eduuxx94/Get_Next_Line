/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:40:12 by ede-alme          #+#    #+#             */
/*   Updated: 2022/08/25 16:24:42 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buff(char *line, char *buffer, t_vars var)
{
	var.i_line = 0;
	var.i_buffer = 0;
	var.temp = line;
	while (var.temp && var.temp[var.i_line])
		var.i_line++;
	while (buffer && buffer[var.i_buffer] && buffer[var.i_buffer++] != '\n')
		if (buffer && buffer[var.i_buffer] == '\n' && var.i_buffer++)
			break ;
	line = malloc(sizeof(char) * (var.i_line + var.i_buffer) + 1);
	if (!line)
		return (NULL);
	line[var.i_line + var.i_buffer] = 0;
	var.i_buffer = 0;
	var.i_line = 0;
	while (var.temp && var.temp[var.i_line] && ++var.i_line)
		line[var.i_line - 1] = var.temp[var.i_line - 1];
	free(var.temp);
	while (buffer && buffer[var.i_buffer] && var.i_buffer < BUFFER_SIZE)
	{
		line[var.i_line + var.i_buffer] = buffer[var.i_buffer];
		buffer[var.i_buffer] = '\0';
		if (line[var.i_line + var.i_buffer++] == '\n')
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	t_vars		var;

	line = NULL;
	while (fd < FOPEN_MAX && fd != -1)
	{
		var.i = 0;
		var.j = 0;
		if (!buffer[fd][0] && read(fd, buffer[fd], BUFFER_SIZE) <= 0)
			return (line);
		line = ft_get_buff(line, buffer[fd], var);
		while (line && var.i < BUFFER_SIZE && buffer[fd][var.i] == '\0')
			var.i++;
		while (var.i < BUFFER_SIZE)
		{
			buffer[fd][var.j++] = buffer[fd][var.i];
			buffer[fd][var.i++] = '\0';
		}
		var.i = 0;
		while (line && line[var.i])
			if (line[var.i++] == '\n')
				return (line);
	}
	return (line);
}
/*
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
*/