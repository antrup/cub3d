/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:33:21 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 12:50:52 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*pts;

	pts = (void*)s;
	i = 0;
	while (i < n)
	{
		if (pts[i] == (unsigned char)c)
			return (&pts[i]);
		i++;
	}
	return (NULL);
}
