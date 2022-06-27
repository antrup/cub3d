/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:45:33 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 14:08:10 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pts1;
	unsigned char	*pts2;
	unsigned long	i;

	if (n == 0)
		return (0);
	pts1 = (void*)s1;
	pts2 = (void*)s2;
	i = 0;
	while (i < n - 1)
	{
		if (pts1[i] != pts2[i])
			return (pts1[i] - pts2[i]);
		i++;
	}
	return (pts1[i] - pts2[i]);
}
