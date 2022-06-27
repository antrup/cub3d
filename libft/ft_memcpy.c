/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:16:27 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/21 18:28:28 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	char			*ptdst;
	char			*ptsrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptdst = dst;
	ptsrc = (void*)src;
	i = 0;
	while (i < n)
	{
		ptdst[i] = ptsrc[i];
		i++;
	}
	return (dst);
}
