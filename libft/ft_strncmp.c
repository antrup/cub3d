/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:52:24 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 17:35:01 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	c1 = 0;
	c2 = 0;
	while (s1[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
		{
			c1 = s1[i];
			c2 = s2[i];
			return (c1 - c2);
		}
		i++;
	}
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}
