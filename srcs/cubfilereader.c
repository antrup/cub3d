/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfilereader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:00:01 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 19:25:39 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <cub3d.h>

static void		init_cubpar(t_cubpar *param)
{
	param->sizex = 800;
	param->sizey = 600;
	param->not = NULL;
	param->sot = NULL;
	param->wet = NULL;
	param->eat = NULL;
	param->st = NULL;
	param->c = 000220100000;
	param->f = 000225030000;
	param->sizemaxx = SCREEN_X_MAX;
	param->sizemaxy = SCREEN_Y_MAX;
}

static int		pre_gnl(int fd, char **buffer)
{
	free(buffer[0]);
	return (get_next_line(fd, buffer));
}

static int		ft_read_cubfile_c(int ***map, int *fd, char ***buffer,
								t_cubpar **param)
{
	while (pre_gnl(*fd, *buffer))
		if (ft_read_map(map, **buffer, ++(fd[1])) == 2)
		{
			ft_clean_map(map, fd[1]);
			return (ft_cleaner(param, buffer, *fd, map));
		}
	if (buffer[0][0][0] != '\0')
		if (ft_read_map(map, **buffer, ++(fd[1])) == 2)
		{
			ft_clean_map(map, fd[1]);
			return (ft_cleaner(param, buffer, *fd, map));
		}
	close(*fd);
	(*param)->line = fd[1];
	return (ft_test_map(map, fd[1], buffer, param));
}

static int		ft_read_cubfile_b(int ***map, int fd, char ***buffer,
									t_cubpar **param)
{
	int line;
	int	test;
	int	dat[2];

	line = 0;
	get_next_line(fd, *buffer);
	while ((test = ft_get_params(**buffer, *param)) == 0)
		pre_gnl(fd, *buffer);
	if (test == 2)
		return (ft_cleaner(param, buffer, fd, map));
	if (ft_read_map(map, **buffer, line) == 2)
	{
		ft_clean_map(map, line);
		return (ft_cleaner(param, buffer, fd, map));
	}
	dat[0] = fd;
	dat[1] = line;
	return (ft_read_cubfile_c(map, dat, buffer, param));
}

t_cubpar		*ft_read_cubfile(int ***map, char *file)
{
	int			fd;
	t_cubpar	*param;
	char		**buffer;

	if (!(param = malloc(sizeof(t_cubpar))) ||
		!(buffer = malloc(sizeof(char*))))
	{
		ft_cleaner(&param, &buffer, -1, map);
		return (NULL);
	}
	init_cubpar(param);
	fd = open(file, O_RDONLY);
	if (ft_read_cubfile_b(map, fd, &buffer, &param) == 2)
		return (NULL);
	ft_cleaner2(&buffer);
	close(fd);
	return (param);
}
