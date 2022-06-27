/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:31:51 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 19:25:08 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"

int			ft_read_map_error(int code)
{
	ft_putstr_fd("Error\n Illegal map\n Error ", 2);
	ft_putnbr_fd(code, 2);
	ft_putstr_fd("\n", 2);
	return (2);
}

static int	test_o(int ***map)
{
	int		i;
	int		y;
	int		line;

	line = 0;
	i = 0;
	while (map[0][line][i] != 9)
	{
		if (map[0][line][i] != 1 && map[0][line][i] != ' ')
			return (ft_read_map_error(21));
		if (map[0][line][i] == ' ')
		{
			y = line;
			while (map[0][y][i] == ' ')
				y++;
			if (map[0][y][i] != 1)
				return (ft_read_map_error(22));
		}
		i++;
	}
	return (0);
}

static int	test_tw(int ***map, int line)
{
	int		i;
	int		y;

	i = 0;
	while (map[0][line][i] != 9)
	{
		if (map[0][line][i] != 1 && map[0][line][i] != ' ')
			return (ft_read_map_error(31));
		if (map[0][line][i] == ' ')
		{
			y = line;
			while (map[0][y][i] == ' ')
				y--;
			if (map[0][y][i] != 1)
				return (ft_read_map_error(32));
		}
		i++;
	}
	return (0);
}

static int	test_th(int ***map, int line)
{
	int		i;
	int		y;
	int		player;

	player = 0;
	y = 0;
	while (y <= line)
	{
		i = 0;
		while (map[0][y][i] != 9)
		{
			if (map[0][y][i] > 68)
			{
				if (player == 0)
					player = 1;
				else
					return (ft_read_map_error(41));
			}
			i++;
		}
		y++;
	}
	if (!player)
		return (ft_read_map_error(42));
	return (0);
}

int			ft_test_map(int ***map, int line, char ***buffer, t_cubpar **param)
{
	if (test_tw(map, line) == 2 || test_o(map) == 2 || test_th(map, line) == 2
		|| test_fo(map, line) == 2 || test_fi(map, line) == 2)
	{
		ft_clean_map(map, line);
		return (ft_cleaner(param, buffer, -1, NULL));
	}
	return (0);
}
