/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:23:31 by ede-alme          #+#    #+#             */
/*   Updated: 2022/08/24 16:45:17 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//Main Function
char	*get_next_line(int fd);

//Utils Functions
char	*ft_get_buff(char *line, char *buffer);
int		ft_lenline(char *str);
void	ft_move_buffer(char *buffer);
int		ft_is_line(char *line);

#endif