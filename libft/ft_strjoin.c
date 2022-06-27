/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:46:07 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/19 09:58:25 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizes1;
	int		sizes2;
	int		i;
	char	*newstr;

	i = 0;
	sizes1 = 0;
	sizes2 = 0;
	if (s1)
		while (s1[i++] != '\0')
			sizes1++;
	i = 0;
	if (s2)
		while (s2[i++] != '\0')
			sizes2++;
	if (!(newstr = malloc(sizeof(char) * (sizes1 + sizes2 + 1))))
		return (NULL);
	i = -1;
	while (i++ < sizes1 - 1)
		newstr[i] = s1[i];
	i--;
	while (i++ - sizes1 < sizes2 - 1)
		newstr[i] = s2[i - sizes1];
	newstr[i] = '\0';
	return (newstr);
}
