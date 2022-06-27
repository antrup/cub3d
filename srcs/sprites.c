/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:35:20 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/16 22:44:51 by atruphem         ###   ########.fr       */
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

t_sprt		*ft_new_sprite(int y, int x, t_sprt *previous)
{
	t_sprt	*new;

	if (!(new = malloc(sizeof(t_sprt))))
		return (NULL);
	if (previous)
		previous->next = new;
	new->x = x + 0.5;
	new->y = y + 0.5;
	new->next = NULL;
	return (new);
}

int			smap_create(t_global *glob)
{
	int		i[2];
	t_sprt	*current;

	i[0] = -1;
	while (++(i[0]) < glob->param->line)
	{
		i[1] = -1;
		while (glob->map[i[0]][++(i[1])] != 9)
		{
			if (glob->map[i[0]][i[1]] == 2)
			{
				if (glob->sprt == NULL)
				{
					if (!(glob->sprt = ft_new_sprite(i[0], i[1], NULL)))
						return (cleaner11(glob));
					current = glob->sprt;
				}
				else if (!(current = ft_new_sprite(i[0], i[1], current)))
					return (cleaner10(glob));
				glob->map[i[0]][i[1]] = 0;
			}
		}
	}
	return (0);
}

void		manage_sprites(t_global *glob)
{
	if (glob->tex[4])
	{
		init_sprite(glob);
		class_sprite(glob);
		ft_print_sprites(glob);
	}
}
