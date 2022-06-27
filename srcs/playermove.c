/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:41:08 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/17 16:29:29 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	move_w(t_global *glob)
{
	if ((glob->map)[(int)(glob->rayp->posy + glob->rayp->dirx * 0.15)]
					[(int)(glob->rayp->posx - glob->rayp->diry * 0.15)] == 0)
	{
		glob->rayp->posx = glob->rayp->posx - glob->rayp->diry * 0.15;
		glob->rayp->posy = glob->rayp->posy + glob->rayp->dirx * 0.15;
		raycaster_loop(glob);
		ft_print_screen(glob);
		manage_sprites(glob);
		put_img(glob);
	}
}

static void	move_e(t_global *glob)
{
	if ((glob->map)[(int)(glob->rayp->posy - glob->rayp->dirx * 0.15)]
					[(int)(glob->rayp->posx + glob->rayp->diry * 0.15)] == 0)
	{
		glob->rayp->posx = glob->rayp->posx + glob->rayp->diry * 0.15;
		glob->rayp->posy = glob->rayp->posy - glob->rayp->dirx * 0.15;
		raycaster_loop(glob);
		ft_print_screen(glob);
		manage_sprites(glob);
		put_img(glob);
	}
}

static void	rote_l(t_global *glob)
{
	double	olddirx;
	double	oldplanex;

	olddirx = glob->rayp->dirx;
	glob->rayp->dirx = glob->rayp->dirx * cos(0.15)
						- glob->rayp->diry * sin(0.15);
	glob->rayp->diry = olddirx * sin(0.15) + glob->rayp->diry * cos(0.15);
	oldplanex = glob->rayp->planex;
	glob->rayp->planex = glob->rayp->planex * cos(0.15)
						- glob->rayp->planey * sin(0.15);
	glob->rayp->planey = oldplanex * sin(0.15)
						+ glob->rayp->planey * cos(0.15);
	raycaster_loop(glob);
	ft_print_screen(glob);
	manage_sprites(glob);
	put_img(glob);
}

static void	rote_r(t_global *glob)
{
	double	olddirx;
	double	oldplanex;

	olddirx = glob->rayp->dirx;
	glob->rayp->dirx = glob->rayp->dirx * cos(-0.15)
						- glob->rayp->diry * sin(-0.15);
	glob->rayp->diry = olddirx * sin(-0.15) + glob->rayp->diry * cos(-0.15);
	oldplanex = glob->rayp->planex;
	glob->rayp->planex = glob->rayp->planex * cos(-0.15)
						- glob->rayp->planey * sin(-0.15);
	glob->rayp->planey = oldplanex * sin(-0.15)
						+ glob->rayp->planey * cos(-0.15);
	raycaster_loop(glob);
	ft_print_screen(glob);
	manage_sprites(glob);
	put_img(glob);
}

int			deal_key(int key, t_global *glob)
{
	if (key == KEY_L_ARROW)
		rote_l(glob);
	else if (key == KEY_R_ARROW)
		rote_r(glob);
	else if (key == KEY_W)
		move_n(glob);
	else if (key == KEY_S)
		move_s(glob);
	else if (key == KEY_A)
		move_e(glob);
	else if (key == KEY_D)
		move_w(glob);
	else if (key == KEY_ESC)
		the_end(glob);
	return (0);
}
