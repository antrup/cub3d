/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:33:57 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:24:37 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					size;
	unsigned int		i;
	char				*str;

	size = 0;
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (size > 0)
	{
		str[i] = f(i, s[i]);
		i++;
		size--;
	}
	str[i] = '\0';
	return (str);
}
