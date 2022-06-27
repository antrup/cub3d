/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:44:04 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 08:47:41 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	cu;
	unsigned char	*ptb;

	ptb = b;
	i = 0;
	cu = c;
	while (i < len)
	{
		ptb[i] = cu;
		i++;
	}
	return (b);
}
