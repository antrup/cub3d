/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:46:05 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/17 17:06:12 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			temp = (char*)(&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		temp = (char*)(&s[i]);
	return (temp);
}
