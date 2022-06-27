/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:04:29 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:20:48 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

void	free_sprt(t_global *glob)
{
	t_sprt		*current;
	t_sprt		*previous;

	while (glob->sprt)
	{
		previous = NULL;
		current = glob->sprt;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		if (current == glob->sprt)
		{
			free(current);
			glob->sprt = NULL;
		}
		else
		{
			free(current);
			previous->next = NULL;
		}
	}
}
