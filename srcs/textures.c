/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:51:16 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:52:43 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static int	get_texture(char *path, t_txtdat *tex, void *id)
{
	if (!(tex->ptr = mlx_xpm_file_to_image(id, path, &(tex->width),
											&(tex->height))))
		return (2);
	tex->memptr = mlx_get_data_addr(tex->ptr, &(tex->bpp),
									&(tex->sizeline), &(tex->endian));
	return (0);
}

static int	load_texture_b(t_global *glob, t_txtdat ***tex)
{
	if (glob->param->wet)
	{
		if (!(tex[0][2] = malloc(sizeof(t_txtdat))))
			return (2);
		if (get_texture(glob->param->wet, tex[0][2], glob->id) == 2)
			return (2);
	}
	if (glob->param->eat)
	{
		if (!(tex[0][3] = malloc(sizeof(t_txtdat))))
			return (2);
		if (get_texture(glob->param->eat, tex[0][3], glob->id) == 2)
			return (2);
	}
	if (glob->param->st)
	{
		if (!(tex[0][4] = malloc(sizeof(t_txtdat))))
			return (2);
		if (get_texture(glob->param->st, tex[0][4], glob->id) == 2)
			return (2);
	}
	return (0);
}

t_txtdat	**load_texture(t_global *glob)
{
	t_txtdat	**tex;
	int			i;

	if (!(tex = malloc(sizeof(t_txtdat *) * 5)))
		return (ft_cleaner4(glob));
	i = -1;
	while (++i < 5)
		tex[i] = NULL;
	if (glob->param->not)
	{
		if (!(tex[0] = malloc(sizeof(t_txtdat))))
			return (ft_cleaner3(glob, &tex));
		if (get_texture(glob->param->not, tex[0], glob->id) == 2)
			return (ft_cleaner3(glob, &tex));
	}
	if (glob->param->sot)
	{
		if (!(tex[1] = malloc(sizeof(t_txtdat))))
			return (ft_cleaner3(glob, &tex));
		if (get_texture(glob->param->sot, tex[1], glob->id) == 2)
			return (ft_cleaner3(glob, &tex));
	}
	if (load_texture_b(glob, &tex) == 2)
		return (ft_cleaner3(glob, &tex));
	return (tex);
}
