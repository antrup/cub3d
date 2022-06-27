/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:00:12 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:44:16 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void	record_player_pos(t_raypar *rayp, int **map, int i, int y)
{
	rayp->posx = i + 0.5;
	rayp->posy = y + 0.5;
	if (map[y][i] == 'N')
	{
		rayp->dirx = 0;
		rayp->diry = -1;
	}
	if (map[y][i] == 'S')
	{
		rayp->dirx = 0;
		rayp->diry = 1;
	}
	if (map[y][i] == 'E')
	{
		rayp->dirx = 1;
		rayp->diry = 0;
	}
	if (map[y][i] == 'W')
	{
		rayp->dirx = -1;
		rayp->diry = 0;
	}
	rayp->planex = rayp->diry * -0.66;
	rayp->planey = rayp->dirx * 0.66;
}

t_raypar	*read_player_pos(int **map, t_global *glob)
{
	int			i;
	int			y;
	int			stop;
	t_raypar	*rayp;

	if (!(rayp = malloc(sizeof(t_raypar))))
		return (ft_cleaner5(glob));
	stop = 0;
	y = -1;
	while (!stop && (++y >= 0))
	{
		i = 0;
		while (map[y][i] != 9)
		{
			if (map[y][i] == 'N' || map[y][i] == 'S' || map[y][i] == 'E'
				|| map[y][i] == 'W')
			{
				record_player_pos(rayp, map, i, y);
				map[y][i] = 0;
				stop = 1;
			}
			i++;
		}
	}
	return (rayp);
}
