/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:50:12 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:43:36 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

static int	ft_get_tx(char *buffer, char **param)
{
	int		i;
	int		fd;

	i = 2;
	while (ft_isspace(buffer[i]))
		i++;
	if (!(*param = malloc(sizeof(char) * (ft_strlen(&buffer[i]) + 1))))
		return (2);
	ft_strlcpy(*param, &buffer[i], ft_strlen(&buffer[i]) + 1);
	if ((fd = open(*param, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\n texture file missing\n", 2);
		return (2);
	}
	else
		close(fd);
	return (0);
}

static int	ft_get_f(char *buffer, t_cubpar *param, int index)
{
	int		i;
	int		ret;

	index == 0 ? param->f = 0 : (void)index;
	ret = 0;
	i = 1;
	while (ft_isspace(buffer[i]))
		i++;
	if (!ft_isdigit(buffer[i]) || ft_atoi(&(buffer[i])) > 255
		|| ft_atoi(&(buffer[i])) < 0)
		return (error_f_c(1));
	ft_get_color((char*)(&(param->f)), ft_atoi(&(buffer[i])), index);
	while (ft_isdigit(buffer[i]) && index != 2)
		i++;
	if (buffer[i] != ',' && index != 2)
		return (error_f_c(1));
	index++;
	if (index < 3)
		ret = ft_get_f(&buffer[i], param, index);
	return (ret);
}

static int	ft_get_c(char *buffer, t_cubpar *param, int index)
{
	int		i;
	int		ret;

	index == 0 ? param->c = 0 : (void)index;
	ret = 0;
	i = 1;
	while (ft_isspace(buffer[i]))
		i++;
	if (!ft_isdigit(buffer[i]) || ft_atoi(&(buffer[i])) > 255
		|| ft_atoi(&(buffer[i])) < 0)
		return (error_f_c(2));
	ft_get_color((char *)(&(param->c)), ft_atoi(&(buffer[i])), index);
	while (ft_isdigit(buffer[i]) && index != 2)
		i++;
	if (buffer[i] != ',' && index != 2)
		return (error_f_c(2));
	index++;
	if (index < 3)
		ret = ft_get_c(&buffer[i], param, index);
	return (ret);
}

static int	ft_get_r(char *buffer, t_cubpar *param)
{
	int		i;

	i = 0;
	i++;
	while (ft_isspace(buffer[i]))
		i++;
	if (!ft_isdigit(buffer[i]))
	{
		ft_putstr_fd("Error\n Illegal resolution\n", 2);
		return (2);
	}
	param->sizex = ft_atoi(&buffer[i]);
	while (ft_isdigit(buffer[i]))
		i++;
	while (ft_isspace(buffer[i]))
		i++;
	if (!ft_isdigit(buffer[i]))
	{
		ft_putstr_fd("Error\n Illegal resolution\n", 2);
		return (2);
	}
	param->sizey = ft_atoi(&buffer[i]);
	return (0);
}

int			ft_get_params(char *buffer, t_cubpar *param)
{
	if (buffer[0] == 'R')
		return (ft_get_r(buffer, param));
	if (buffer[0] == 'N' && buffer[1] == 'O')
		return (ft_get_tx(buffer, &(param->not)));
	if (buffer[0] == 'S' && buffer[1] == 'O')
		return (ft_get_tx(buffer, &(param->sot)));
	if (buffer[0] == 'W' && buffer[1] == 'E')
		return (ft_get_tx(buffer, &(param->wet)));
	if (buffer[0] == 'E' && buffer[1] == 'A')
		return (ft_get_tx(buffer, &(param->eat)));
	if (buffer[0] == 'S')
		return (ft_get_tx(buffer, &(param->st)));
	if (buffer[0] == 'F')
		return (ft_get_f(buffer, param, 0));
	if (buffer[0] == 'C')
		return (ft_get_c(buffer, param, 0));
	if (buffer[0] == '\n')
		return (0);
	if (buffer[0] == ' ' || buffer[0] == '1')
		return (1);
	return (2);
}
