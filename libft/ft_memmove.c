/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:47:51 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/18 10:51:35 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned char	*ptdst;
	unsigned char	*ptsrc;

	ptdst = dst;
	ptsrc = (void*)src;
	if (src < dst)
	{
		i = len - 1;
		while (i < len)
		{
			ptdst[i] = ptsrc[i];
			i--;
		}
	}
	else if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			ptdst[i] = ptsrc[i];
			i++;
		}
	}
	return (dst);
}
