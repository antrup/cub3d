/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:06:17 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:21:17 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "cub3d.h"
#include "libft.h"

void		ft_default_wall(t_global *glob, int *x, int *y)
{
	int		color;
	int		*paste;

	color = 255;
	while (*y < glob->ray[*x].printstop)
	{
		paste = (int *)(glob->img->memptr) + *y * glob->img->sizeline / 4 + *x;
		ft_memcpy(paste, &color, 4);
		(*y)++;
	}
}

void		ft_txt_wall(t_global *glob, int *x, int *y, int index)
{
	int		*color;
	int		*paste;

	glob->tex[index]->step = (double)(glob->tex[index]->height)
										/ glob->ray[*x].printheight;
	if (glob->ray[*x].printstart == 0)
		glob->tex[index]->txpos = (glob->ray[*x].printheight
							- glob->param->sizey) / 2 * glob->tex[index]->step;
	else
		glob->tex[index]->txpos = 0;
	while (*y < glob->ray[*x].printstop)
	{
		color = (int *)(glob->tex[index]->memptr)
					+ (int)(glob->tex[index]->txpos)
					* glob->tex[index]->sizeline / 4 + glob->tex[index]->txtx;
		paste = (int *)(glob->img->memptr) + *y * glob->img->sizeline / 4 + *x;
		ft_memcpy(paste, color, 4);
		(*y)++;
		glob->tex[index]->txpos = glob->tex[index]->txpos
									+ glob->tex[index]->step;
	}
}

static void	ft_print_wall_b(t_global *glob, int *x, int *y)
{
	if (glob->ray[*x].dirx > 0)
	{
		if (!(glob->param->eat))
			ft_default_wall(glob, x, y);
		else
		{
			glob->tex[3]->txtx = (int)(glob->ray[*x].wallx
										* (double)(glob->tex[3]->width));
			glob->tex[3]->txtx = glob->tex[3]->width - glob->tex[3]->txtx;
			ft_txt_wall(glob, x, y, 3);
		}
	}
	else
	{
		if (!(glob->param->wet))
			ft_default_wall(glob, x, y);
		else
		{
			glob->tex[2]->txtx = (int)(glob->ray[*x].wallx
										* (double)(glob->tex[2]->width));
			ft_txt_wall(glob, x, y, 2);
		}
	}
}

static void	ft_print_wallc(t_global *glob, int *x, int *y)
{
	if (!(glob->param->sot))
		ft_default_wall(glob, x, y);
	else
	{
		glob->tex[1]->txtx = (int)(glob->ray[*x].wallx
									* (double)(glob->tex[1]->width));
		glob->tex[1]->txtx = glob->tex[1]->width - glob->tex[1]->txtx;
		ft_txt_wall(glob, x, y, 1);
	}
}

void		ft_print_wall(t_global *glob, int *x, int *y)
{
	if (glob->ray[*x].whwall == 1)
		ft_print_wall_b(glob, x, y);
	else
	{
		if (glob->ray[*x].diry > 0)
		{
			if (!(glob->param->not))
				ft_default_wall(glob, x, y);
			else
			{
				glob->tex[0]->txtx = (int)(glob->ray[*x].wallx
											* (double)(glob->tex[0]->width));
				ft_txt_wall(glob, x, y, 0);
			}
		}
		else
			ft_print_wallc(glob, x, y);
	}
}
