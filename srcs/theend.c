/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:04:37 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:03:40 by atruphem         ###   ########.fr       */
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

int	the_end2(t_global *glob)
{
	ft_clean_map(&(glob->map), glob->param->line);
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
	mlx_destroy_image(glob->id, glob->img->ptr);
	free(glob->img);
	mlx_destroy_window(glob->id, glob->wid);
	if (!MACOSX)
		mlx_destroy_display(glob->id);
	free(glob->id);
	free_sprt(glob);
	exit(0);
	return (0);
}

int	the_end(t_global *glob)
{
	ft_clean_map(&(glob->map), glob->param->line);
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
	mlx_destroy_image(glob->id, glob->img->ptr);
	free(glob->img);
	mlx_destroy_window(glob->id, glob->wid);
	if (!MACOSX)
		mlx_destroy_display(glob->id);
	free(glob->id);
	free_sprt(glob);
	exit(0);
	return (0);
}
