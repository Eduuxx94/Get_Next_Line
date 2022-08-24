/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:22:24 by ede-alme          #+#    #+#             */
/*   Updated: 2022/08/24 16:23:06 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_move_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buffer[i] == '\0')
		i++;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		buffer[i] = '\0';
		j++;
		i++;
	}
}

int	ft_lenline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_get_buff(char *line, char *buffer)
{
	int		i_line;
	int		i_buffer;
	char	*temp;

	i_line = 0;
	i_buffer = 0;
	temp = line;
	line = malloc(sizeof(char) * (ft_lenline(temp) + ft_lenline(buffer)) + 1);
	line[ft_lenline(temp) + ft_lenline(buffer)] = 0;
	while (temp && temp[i_line] && ++i_line)
		line[i_line - 1] = temp[i_line - 1];
	if (temp)
		free(temp);
	while (buffer && buffer[i_buffer] && i_buffer < BUFFER_SIZE)
	{
		line[i_line + i_buffer] = buffer[i_buffer];
		buffer[i_buffer] = '\0';
		if (line[i_line + i_buffer] == '\n')
			break ;
		i_buffer++;
	}
	ft_move_buffer(buffer);
	return (line);
}
