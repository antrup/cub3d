/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:13:09 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:20:23 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"
#include <math.h>

void	ft_print_screen(t_global *glob)
{
	int		x;
	int		y;
	int		*paste;

	x = 0;
	while (x < glob->param->sizex)
	{
		y = 0;
		while (y < glob->ray[x].printstart)
		{
			paste = (int *)(glob->img->memptr) + y * glob->img->sizeline
					/ 4 + x;
			ft_memcpy(paste, &(glob->param->c), 4);
			y++;
		}
		ft_print_wall(glob, &x, &y);
		while (y < glob->param->sizey)
		{
			paste = (int *)(glob->img->memptr) + y * glob->img->sizeline
					/ 4 + x;
			ft_memcpy(paste, &(glob->param->f), 4);
			y++;
		}
		x++;
	}
}

int		put_img(t_global *glob)
{
	mlx_put_image_to_window(glob->id, glob->wid, glob->img->ptr, 0, 0);
	return (0);
}

int		set_img(t_global *glob)
{
	if (!(glob->img = malloc(sizeof(t_txtdat))))
		return (cleaner10(glob));
	if (!(glob->img->ptr = mlx_new_image(glob->id, glob->param->sizex,
											glob->param->sizey)))
		return (cleaner12(glob));
	glob->img->memptr = mlx_get_data_addr(glob->img->ptr, &(glob->img->bpp),
						&(glob->img->sizeline), &(glob->img->endian));
	return (0);
}
