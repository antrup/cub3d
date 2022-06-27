/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmapc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:49:09 by atruphem          #+#    #+#             */
/*   Updated: 2021/01/22 14:11:04 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <cub3d.h>

static int	test_fo_c(int ***map, int size, int i, int y)
{
	if (i > size)
	{
		while (i >= size)
		{
			if (map[0][y][i] != 1)
				return (ft_read_map_error(51));
			i--;
		}
	}
	else if (i < size)
	{
		while (i <= size)
		{
			if (map[0][y - 1][i] != 1)
				return (ft_read_map_error(52));
			i++;
		}
	}
	return (0);
}

static int	test_fo_b(int ***map, int line, int size, int y)
{
	int		i;
	int		tmp;

	while (++y <= line)
	{
		i = 0;
		while (map[0][y][i] != 9)
			i++;
		while (map[0][y][i] == 9 || map[0][y][i] == ' ')
			i--;
		tmp = i;
		if (test_fo_c(map, size, i, y) == 2)
			return (2);
		size = tmp;
	}
	return (0);
}

int			test_fo(int ***map, int line)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (map[0][y][i] != 9)
		i++;
	i--;
	while (map[0][y][i] == ' ')
		i--;
	return (test_fo_b(map, line, i, y));
}
