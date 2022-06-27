/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:45:05 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/20 12:42:04 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long		i;
	char				*pts;

	if (!(pts = (malloc(size * count))))
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		pts[i] = 0;
		i++;
	}
	return (pts);
}
