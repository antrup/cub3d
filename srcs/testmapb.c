/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmapb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:49:09 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:50:54 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <cub3d.h>

static int	test_fi_c(int ***map, int i, int y)
{
	if (map[0][y][i + 1] != 1 && map[0][y][i + 1] != 32
		&& map[0][y][i + 1] != 9)
		return (ft_read_map_error(73));
	if (i > 0)
		if (map[0][y][i - 1] != 1 && map[0][y][i - 1] != 32)
			return (ft_read_map_error(74));
	return (0);
}

static int	test_fi_b(int ***map, int line, int i, int y)
{
	int		z;
	int		sizem;
	int		sizep;

	sizem = 0;
	sizep = 0;
	y > 0 ? (sizem = size_line(map, y - 1)) : (void)sizem;
	y < line ? (sizep = size_line(map, y + 1)) : (void)sizep;
	if (y > 0)
	{
		z = i - 2;
		while (++z < i + 2)
			if (z > 0 && z <= sizem)
				if (map[0][y - 1][z] != 1 && map[0][y - 1][z] != 32)
					return (ft_read_map_error(71));
	}
	if (y < line)
	{
		z = i - 2;
		while (++z < i + 2)
			if (z > 0 && z <= sizep)
				if (map[0][y + 1][z] != 1 && map[0][y + 1][z] != 32)
					return (ft_read_map_error(72));
	}
	return (test_fi_c(map, i, y));
}

int			test_fi(int ***map, int line)
{
	int		i;
	int		y;

	y = 0;
	while (y <= line)
	{
		i = 0;
		while (map[0][y][i] != 9)
		{
			if (map[0][y][i] == 32)
				if (test_fi_b(map, line, i, y) == 2)
					return (2);
			i++;
		}
		y++;
	}
	return (0);
}
