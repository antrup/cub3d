/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:51:36 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/23 14:30:44 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	char			*copy;
	unsigned long	j;
	unsigned int	size;

	if (s == NULL)
		return (NULL);
	i = -1;
	size = 0;
	while (s[++i] != '\0')
		size++;
	if (start > size - 1)
		len = 0;
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len && s[i] != '\0')
	{
		copy[j] = s[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
