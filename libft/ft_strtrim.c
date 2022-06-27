/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:58:55 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:41:08 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strstart(int *size, char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0' && s1[*size] != '\0')
	{
		if (s1[*size] == set[i])
		{
			(*size)++;
			i = 0;
		}
		else
			i++;
	}
	return (*size);
}

static void		ft_strstop(int *size, char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0' && *size >= 0)
	{
		if (s1[*size] == set[i])
		{
			(*size)--;
			i = 0;
		}
		else
			i++;
	}
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*clean;
	int		size;
	int		i;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = 0;
	start = ft_strstart(&size, s1, set);
	while (s1[size] != '\0')
		size++;
	size--;
	ft_strstop(&size, s1, set);
	if (size < start)
		start = size + 1;
	if (!(clean = malloc(sizeof(char) * ((size - start) + 2))))
		return (NULL);
	i = 0;
	while (start <= size)
		clean[i++] = s1[start++];
	clean[i] = '\0';
	return (clean);
}
