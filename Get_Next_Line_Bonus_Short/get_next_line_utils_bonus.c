/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:22:24 by ede-alme          #+#    #+#             */
/*   Updated: 2022/08/25 11:19:28 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_buff(char *line, char *buffer, t_vars var)
{
	var.i_line = 0;
	var.i_buffer = 0;
	var.temp = line;
	while (var.temp && var.temp[var.i_line] && var.temp[var.i_line++] != '\n')
		if (var.temp && var.temp[var.i_line] == '\n' && var.i_line++)
			break ;
	while (buffer && buffer[var.i_buffer] && buffer[var.i_buffer++] != '\n')
		if (buffer && buffer[var.i_buffer] == '\n' && var.i_buffer++)
			break ;
	line = malloc(sizeof(char) * (var.i_line + var.i_buffer) + 1);
	line[var.i_line + var.i_buffer] = 0;
	var.i_buffer = 0;
	var.i_line = 0;
	while (var.temp && var.temp[var.i_line] && ++var.i_line)
		line[var.i_line - 1] = var.temp[var.i_line - 1];
	if (var.temp)
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
