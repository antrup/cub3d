/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:23:51 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:27:05 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <cub3d.h>

static int		ft_record_map(int ***map, char *buffer, int *pos)
{
	while (buffer[++(pos[0])] != '\0')
		if (buffer[pos[0]] == ' ')
			map[0][pos[1]][++(pos[2])] = ' ';
		else if (buffer[pos[0]] == '1' || buffer[pos[0]] == '2'
					|| buffer[pos[0]] == '0')
			map[0][pos[1]][++(pos[2])] = buffer[pos[0]] - 48;
		else if (buffer[pos[0]] == 'N' || buffer[pos[0]] == 'S'
					|| buffer[pos[0]] == 'W' || buffer[pos[0]] == 'E')
			map[0][pos[1]][++(pos[2])] = buffer[pos[0]];
		else
			return (ft_read_map_error(1));
	map[0][pos[1]][++(pos[2])] = 9;
	while (buffer[pos[0] - 1] == ' ')
		(pos[0])--;
	if (buffer[pos[0] - 1] != '1')
		return (ft_read_map_error(2));
	return (0);
}

int				ft_read_map(int ***map, char *buffer, int line)
{
	int		pos[3];
	int		i;
	int		col;

	i = -1;
	col = -1;
	if (!(map[0][line] = malloc(sizeof(int) * (ft_strlen(buffer) + 1))))
		return (2);
	while (buffer[++i] == ' ')
		map[0][line][++col] = ' ';
	if (buffer[i] != '1' && buffer[i] != '\0')
		return (ft_read_map_error(3));
	i--;
	pos[0] = i;
	pos[1] = line;
	pos[2] = col;
	return (ft_record_map(map, buffer, pos));
}

int				ft_size_map(char *file)
{
	char	*buffer;
	int		size;
	int		fd;
	int		r;

	if (!(buffer = malloc(sizeof(char*) * BUFFER_SIZE)))
		return (2);
	size = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		free(buffer);
		return (-1);
	}
	while ((r = read(fd, buffer, BUFFER_SIZE)))
		size = size + ft_count_line(buffer, r);
	free(buffer);
	close(fd);
	return (size);
}
