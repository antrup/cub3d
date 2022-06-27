/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermoveb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:34:26 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/17 12:43:54 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_n(t_global *glob)
{
	if ((glob->map)[(int)(glob->rayp->posy + glob->rayp->diry * 0.15)]
					[(int)(glob->rayp->posx + glob->rayp->dirx * 0.15)] == 0)
	{
		glob->rayp->posx = glob->rayp->posx + glob->rayp->dirx * 0.15;
		glob->rayp->posy = glob->rayp->posy + glob->rayp->diry * 0.15;
		raycaster_loop(glob);
		ft_print_screen(glob);
		manage_sprites(glob);
		put_img(glob);
	}
}

void	move_s(t_global *glob)
{
	if ((glob->map)[(int)(glob->rayp->posy - glob->rayp->diry * 0.15)]
					[(int)(glob->rayp->posx - glob->rayp->dirx * 0.15)] == 0)
	{
		glob->rayp->posx = glob->rayp->posx - glob->rayp->dirx * 0.15;
		glob->rayp->posy = glob->rayp->posy - glob->rayp->diry * 0.15;
		raycaster_loop(glob);
		ft_print_screen(glob);
		manage_sprites(glob);
		put_img(glob);
	}
}
