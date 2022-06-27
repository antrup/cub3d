/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:15:57 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:26:41 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "libft.h"
#include "get_next_line_bonus.h"

void		*ft_cleaner3(t_global *glob, t_txtdat ***tex)
{
	free(glob->param->not);
	free(glob->param->sot);
	free(glob->param->eat);
	free(glob->param->wet);
	free(glob->param->st);
	free_txts_sp(glob, *tex);
	free(tex[0]);
	free(glob->param);
	free(glob->ray);
	free(glob->rayp);
	mlx_destroy_window(glob->id, glob->wid);
	free(glob->id);
	free_sprt(glob);
	return (NULL);
}

void		*ft_cleaner4(t_global *glob)
{
	free(glob->param->not);
	free(glob->param->sot);
	free(glob->param->eat);
	free(glob->param->wet);
	free(glob->param->st);
	free(glob->param);
	free(glob->ray);
	free(glob->rayp);
	mlx_destroy_window(glob->id, glob->wid);
	free(glob->id);
	free_sprt(glob);
	return (NULL);
}

void		*ft_cleaner5(t_global *glob)
{
	free(glob->param->not);
	free(glob->param->sot);
	free(glob->param->eat);
	free(glob->param->wet);
	free(glob->param->st);
	free(glob->param);
	free(glob->ray);
	mlx_destroy_window(glob->id, glob->wid);
	free(glob->id);
	free_sprt(glob);
	return (NULL);
}

int			ft_cleaner(t_cubpar **param, char ***buffer, int fd, int ***map)
{
	if (fd > 0)
	{
		free(**buffer);
		while (get_next_line(fd, *buffer))
			free(**buffer);
	}
	free((*param)->not);
	free((*param)->sot);
	free((*param)->eat);
	free((*param)->wet);
	free((*param)->st);
	free(*param);
	free(**buffer);
	free(*buffer);
	if (map)
		free(*map);
	ft_putstr_fd("Error\nInvalid cub file\n", 2);
	if (fd != -1)
		close(fd);
	return (2);
}

void		ft_cleaner2(char ***buffer)
{
	free(**buffer);
	free(*buffer);
}
