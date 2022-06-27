/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:04:37 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/24 00:03:35 by atruphem         ###   ########.fr       */
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

static void	init_mlx_loop(t_global *glob)
{
	put_img(glob);
	mlx_key_hook(glob->wid, deal_key, glob);
	mlx_hook(glob->wid, EXIT_EVENT, 0L, the_end, glob);
	mlx_expose_hook(glob->wid, put_img, glob);
	mlx_loop(glob->id);
}

int			raycaster_init(t_cubpar *param, int **map)
{
	t_global	glob;

	glob.param = param;
	if (!(glob.id = mlx_init()) || !(resize_screen(param, glob.id)) ||
	!(glob.wid = mlx_new_window(glob.id, param->sizex, param->sizey, "cub3d")))
		return (error_dp());
	if (!(glob.ray = malloc(sizeof(t_raydat) * param->sizex)))
		return (2);
	if (!(glob.rayp = read_player_pos(map, &glob)))
		return (2);
	glob.map = map;
	glob.sprt = NULL;
	if (smap_create(&glob) == 2 || set_img(&glob) == 2)
		return (2);
	raycaster_loop(&glob);
	if (!(glob.tex = load_texture(&glob)))
		return (2);
	ft_print_screen(&glob);
	if (glob.tex[4])
		ft_print_sprites(&glob);
	if (!glob.param->bmp)
		init_mlx_loop(&glob);
	else
		save_as_bmp(&glob);
	return (0);
}

int			test_arg(char *arg)
{
	char	*test;

	test = "--save";
	return (ft_strncmp(arg, test, 7));
}

int			main(int argc, char **argv)
{
	int			**map;
	char		*file;
	t_cubpar	*param;
	int			bmp;

	if (argc > 3 || argc < 1)
		return (error_dp("Error\nIncorrect number of arguments\n"));
	bmp = 0;
	if (argc == 3)
	{
		if (test_arg(argv[2]) != 0)
			return (error_dp("Error\nIncorrect argument"));
		bmp = 1;
	}
	file = argv[1];
	if (ft_size_map(file) == -1)
		return (error_dp("Error\ncub file missing"));
	if (!(map = malloc(sizeof(int*) * ft_size_map(file))))
		return (2);
	if (!(param = ft_read_cubfile(&map, file)))
		return (2);
	param->bmp = bmp;
	raycaster_init(param, map);
	ft_clean_map(&map, param->line);
	return (2);
}
