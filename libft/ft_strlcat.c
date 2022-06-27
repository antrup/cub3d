/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:05:27 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/18 10:49:47 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	int				srcsize;

	srcsize = 0;
	i = 0;
	while (src[i] != '\0')
	{
		srcsize++;
		i++;
	}
	j = 0;
	while (dst[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i < size - j - 1 && size > j + 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (size > j)
		dst[j + i] = '\0';
	if (size < j)
		return (size + srcsize);
	return (j + srcsize);
}
