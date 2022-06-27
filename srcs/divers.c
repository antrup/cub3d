/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:59:13 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 21:59:47 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int		resize_screen(t_cubpar *param, void *id)
{
	if (MACOSX)
	{
		if (param->sizex > SCREEN_X_MAX)
			param->sizex = SCREEN_X_MAX;
		if (param->sizey > SCREEN_Y_MAX)
			param->sizey = SCREEN_Y_MAX;
	}
	else
	{
		mlx_get_screen_size(id, &(param->sizemaxx), &(param->sizemaxy));
		if (param->sizex > param->sizemaxx)
			param->sizex = param->sizemaxx;
		if (param->sizey > param->sizemaxy)
			param->sizey = param->sizemaxy;
	}
	return (1);
}
