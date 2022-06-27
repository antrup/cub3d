/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:46 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/18 12:32:18 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned long	size;
	char			*copy;
	unsigned long	i;

	size = 0;
	i = 0;
	while (s1[size] != '\0')
		size++;
	copy = malloc(sizeof(char) * size + 1);
	if (copy == NULL)
		return (NULL);
	while (i <= size)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
