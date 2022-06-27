/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:46:06 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:22:59 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		size;
	int		i;

	if (s == NULL)
		return ;
	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	write(fd, s, size);
	write(fd, "\n", 1);
}
