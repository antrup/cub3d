/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:43:47 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:46:14 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include <stdlib.h>

void			class_sprite(t_global *glob)
{
	t_sprt	*current;
	t_sprt	*tmp;
	t_sprt	*previous;

	previous = NULL;
	current = glob->sprt;
	while (current && current->next != NULL)
	{
		if (current->sprtdist < current->next->sprtdist)
		{
			(current != glob->sprt) ? (previous->next = current->next) : NULL;
			(current == glob->sprt) ? (glob->sprt = current->next) : NULL;
			tmp = current->next;
			current->next = current->next->next;
			tmp->next = current;
			current = glob->sprt;
			previous = NULL;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

static void		init_spriteb(t_global *glob, t_sprt *current)
{
	if ((current->starty = -current->height / 2
							+ glob->param->sizey / 2) < 0)
		current->starty = 0;
	if ((current->stopy = current->height / 2
							+ glob->param->sizey / 2) > glob->param->sizey)
		current->starty = glob->param->sizey;
	current->width = abs((int)(glob->param->sizey / (current->transformy)));
	if ((current->startx = -current->width / 2 + current->screenx) < 0)
		current->startx = 0;
	if ((current->stopx = current->width / 2 + current->screenx)
			> glob->param->sizex)
		current->stopx = glob->param->sizex;
}

void			init_sprite(t_global *glob)
{
	t_sprt	*current;
	double	inv;

	inv = 1.0 / (glob->rayp->planex * glob->rayp->diry - glob->rayp->dirx
					* glob->rayp->planey);
	current = glob->sprt;
	while (current)
	{
		current->sprtdist = (glob->rayp->posx - current->x)
		* (glob->rayp->posx - current->x) + (glob->rayp->posy - current->y)
		* (glob->rayp->posy - current->y);
		current->sprtx = current->x - glob->rayp->posx;
		current->sprty = current->y - glob->rayp->posy;
		current->transformx = inv * (glob->rayp->diry * current->sprtx
										- glob->rayp->dirx * current->sprty);
		current->transformy = inv * (-glob->rayp->planey * current->sprtx
										+ glob->rayp->planex * current->sprty);
		current->screenx = (int)((glob->param->sizex / 2)
							* (1 + current->transformx / current->transformy));
		current->height = abs((int)(glob->param->sizey
									/ (current->transformy)));
		init_spriteb(glob, current);
		current = current->next;
	}
}
