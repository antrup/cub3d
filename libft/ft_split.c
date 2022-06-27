/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:34:03 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/23 17:35:20 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_creatab(char const *s, char c)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (!(tab = malloc(sizeof(char*) * (count + 2))))
		return (NULL);
	return (tab);
}

static int	ft_copypart(int *count, char **tab, char const *s, int *i)
{
	int		k;

	k = 0;
	if (!(tab[i[1]] = malloc(sizeof(char) * (*count + 1))))
		return (-1);
	while (*count > 0)
	{
		tab[i[1]][k] = s[i[0] - *count];
		k++;
		(*count)--;
	}
	tab[i[1]][k] = '\0';
	(i[1])++;
	return (0);
}

static void	ft_clean(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static void	ft_increasecpt(int *count, int *i)
{
	(*count)++;
	(i[0])++;
}

char		**ft_split(char const *s, char c)
{
	int		count;
	int		i[2];
	char	**tab;

	if (s == NULL || !(tab = ft_creatab(s, c)))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	count = 0;
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] != c & s[i[0]] != '\0')
			ft_increasecpt(&count, i);
		if (count > 0)
			if (ft_copypart(&count, tab, s, i) == -1)
			{
				ft_clean(tab, i[1] - 1);
				return (NULL);
			}
		if (s[i[0]] != '\0')
			i[0]++;
	}
	tab[i[1]] = NULL;
	return (tab);
}
