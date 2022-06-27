/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:41:28 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:56:29 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bmphdata	*init_bmp_data(t_global *glob)
{
	t_bmphdata		*data;

	if (!(data = malloc(sizeof(t_bmphdata))))
		return (NULL);
	data->hfield[0] = 'B';
	data->hfield[1] = 'M';
	data->fsize = glob->param->sizex * glob->param->sizey * 4 + 54;
	data->lol = 42;
	data->offset = 54;
	data->hsize = 40;
	data->width = glob->param->sizex;
	data->height = glob->param->sizey;
	data->colorp = 1;
	data->bpp = 32;
	data->compression = 0;
	data->isize = glob->param->sizex * glob->param->sizey * 4;
	data->hppm = 0;
	data->vppm = 0;
	data->nbcolors = 0;
	data->impcolors = 0;
	return (data);
}

static void			put_header(int fd, t_bmphdata *data)
{
	write(fd, &(data->hfield), 2);
	write(fd, &(data->fsize), 4);
	write(fd, &(data->lol), 4);
	write(fd, &(data->offset), 4);
	write(fd, &(data->hsize), 4);
	write(fd, &(data->width), 4);
	write(fd, &(data->height), 4);
	write(fd, &(data->colorp), 2);
	write(fd, &(data->bpp), 2);
	write(fd, &(data->compression), 4);
	write(fd, &(data->isize), 4);
	write(fd, &(data->hppm), 4);
	write(fd, &(data->vppm), 4);
	write(fd, &(data->nbcolors), 4);
	write(fd, &(data->impcolors), 4);
}

void				save_as_bmp(t_global *glob)
{
	int			fd;
	t_bmphdata	*data;
	int			y;
	int			x;

	if ((fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR)) < 0)
		the_end2(glob);
	if (!(data = init_bmp_data(glob)))
	{
		close(fd);
		the_end2(glob);
	}
	put_header(fd, data);
	y = 0;
	while (++y <= glob->param->sizey)
	{
		x = -1;
		while (++x < glob->param->sizex)
			write(fd, glob->img->memptr + data->isize - glob->img->sizeline
						* y + x * 4, 4);
	}
	close(fd);
	free(data);
	the_end2(glob);
}
