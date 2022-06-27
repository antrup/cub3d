/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:11:58 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 10:29:59 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*ptdst;
	unsigned char	*ptsrc;

	ptdst = dst;
	ptsrc = (void*)src;
	i = 0;
	while (i < n)
	{
		ptdst[i] = ptsrc[i];
		i++;
		if (ptsrc[i - 1] == (unsigned char)c)
			return (&ptdst[i]);
	}
	return (NULL);
}
