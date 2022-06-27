/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:22:29 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:56:56 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include "cub3d.h"
#include <math.h>

static void	ft_print_spritesc(t_sprt *current, t_global *glob, int x)
{
	int		y;
	int		*color;
	int		*paste;

	y = current->starty;
	glob->tex[4]->step = (double)(glob->tex[4]->height) / current->height;
	if (current->starty == 0)
		glob->tex[4]->txpos = (current->height - glob->param->sizey)
								/ 2 * glob->tex[4]->step;
	else
		glob->tex[4]->txpos = 0;
	while (y < current->stopy)
	{
		color = (int *)(glob->tex[4]->memptr) + (int)(glob->tex[4]->txpos)
						* glob->tex[4]->sizeline / 4 + glob->tex[4]->txtx;
		if (*color != 0)
		{
			paste = (int *)(glob->img->memptr) + y
					* glob->img->sizeline / 4 + x;
			ft_memcpy(paste, color, 4);
		}
		y++;
		glob->tex[4]->txpos = glob->tex[4]->txpos + glob->tex[4]->step;
	}
}

static void	ft_print_spritesb(t_sprt *current, t_global *glob)
{
	int		x;

	x = current->startx;
	while (x < current->stopx)
	{
		glob->tex[4]->txtx = (int)((256 * (x - (-current->width / 2
								+ current->screenx)) * glob->tex[4]->width
								/ current->width / 256));
		if (current->transformy > 0
			&& current->transformy < glob->ray[x].disttowall)
		{
			ft_print_spritesc(current, glob, x);
		}
		x++;
	}
}

void		ft_print_sprites(t_global *glob)
{
	t_sprt *current;

	current = glob->sprt;
	while (current)
	{
		ft_print_spritesb(current, glob);
		current = current->next;
	}
}
