/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:58:30 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:26:11 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "libft.h"
#include "get_next_line_bonus.h"

void		free_txts_sp(t_global *glob, t_txtdat **tex)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (tex[i])
		{
			mlx_destroy_image(glob->id, tex[i]->ptr);
			free(tex[i]);
			tex[i] = NULL;
		}
		i++;
	}
}

void		free_txts(t_global *glob)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (glob->tex[i])
		{
			mlx_destroy_image(glob->id, glob->tex[i]->ptr);
			free(glob->tex[i]);
			glob->tex[i] = NULL;
		}
		i++;
	}
}

int			cleaner12(t_global *glob)
{
	free(glob->param->not);
	free(glob->param->sot);
	free(glob->param->eat);
	free(glob->param->wet);
	free(glob->param->st);
	free_txts(glob);
	free(glob->tex);
	free(glob->param);
	free(glob->ray);
	free(glob->rayp);
	mlx_destroy_window(glob->id, glob->wid);
	if (!MACOSX)
		mlx_destroy_display(glob->id);
	free(glob->id);
	free_sprt(glob);
	free(glob->img);
	return (2);
}

int			cleaner10(t_global *glob)
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
	if (!MACOSX)
		mlx_destroy_display(glob->id);
	free(glob->id);
	free_sprt(glob);
	return (2);
}

int			cleaner11(t_global *glob)
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
	if (!MACOSX)
		mlx_destroy_display(glob->id);
	free(glob->id);
	return (2);
}
