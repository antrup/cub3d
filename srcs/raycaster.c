/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:42:34 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:49:43 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include <stdlib.h>

static void	ft_ray_init_b(t_raydat *ray, t_raypar *rayp)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->tox = (rayp->posx - ray->mapx) * ray->nextx;
	}
	else
	{
		ray->stepx = 1;
		ray->tox = (ray->mapx + 1 - rayp->posx) * ray->nextx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->toy = (rayp->posy - ray->mapy) * ray->nexty;
	}
	else
	{
		ray->stepy = 1;
		ray->toy = (ray->mapy + 1 - rayp->posy) * ray->nexty;
	}
}

static void	ft_ray_init(int x, t_raydat *ray, t_raypar *rayp, t_cubpar *param)
{
	ray->screenx = 2 * x / (double)(param->sizex) - 1;
	ray->dirx = rayp->dirx + rayp->planex * ray->screenx;
	ray->diry = rayp->diry + rayp->planey * ray->screenx;
	ray->mapx = (int)(rayp->posx);
	ray->mapy = (int)(rayp->posy);
	if (ray->diry == 0)
	{
		ray->nextx = 0;
		ray->nexty = 1;
	}
	else if (ray->dirx == 0)
	{
		ray->nextx = 1;
		ray->nexty = 0;
	}
	else
	{
		ray->nextx = fabs(1 / ray->dirx);
		ray->nexty = fabs(1 / ray->diry);
	}
	ray->wall = 0;
	ray->whwall = 0;
	ft_ray_init_b(ray, rayp);
}

static void	ft_find_wall_b(t_raydat *ray, t_raypar *rayp)
{
	if (ray->whwall == 1)
	{
		ray->disttowall = (ray->mapx - rayp->posx + (1 - ray->stepx) / 2)
							/ ray->dirx;
		ray->wallx = rayp->posy + ray->disttowall * ray->diry;
	}
	else
	{
		ray->disttowall = (ray->mapy - rayp->posy + (1 - ray->stepy) / 2)
							/ ray->diry;
		ray->wallx = rayp->posx + ray->disttowall * ray->dirx;
	}
	ray->wallx = ceil(ray->wallx) - ray->wallx;
}

static void	ft_find_wall(int **map, t_raydat *ray, t_raypar *rayp)
{
	while (ray->wall == 0)
	{
		if (ray->tox < ray->toy)
		{
			ray->tox = ray->tox + ray->nextx;
			ray->mapx = ray->mapx + ray->stepx;
			ray->whwall = 1;
		}
		else
		{
			ray->toy = ray->toy + ray->nexty;
			ray->mapy = ray->mapy + ray->stepy;
			ray->whwall = 2;
		}
		if (map[ray->mapy][ray->mapx] > 0)
			ray->wall = 1;
	}
	ft_find_wall_b(ray, rayp);
}

void		raycaster_loop(t_global *glob)
{
	int			x;

	x = 0;
	while (x < glob->param->sizex)
	{
		ft_ray_init(x, &(glob->ray[x]), glob->rayp, glob->param);
		ft_find_wall(glob->map, &(glob->ray[x]), glob->rayp);
		(glob->ray[x]).printheight = (int)(glob->param->sizey
											/ (glob->ray[x]).disttowall);
		if ((glob->ray[x].printstart = -(glob->ray[x].printheight) / 2
											+ glob->param->sizey / 2) < 0)
			glob->ray[x].printstart = 0;
		if ((glob->ray[x].printstop = glob->ray[x].printstart
				+ glob->ray[x].printheight) > glob->param->sizey)
			glob->ray[x].printstop = glob->param->sizey;
		x++;
	}
	init_sprite(glob);
	class_sprite(glob);
}
