/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:48:27 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/20 11:49:56 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putnbr_fd(int n, int fd)
{
	long	nl;
	long	tmpnl;
	char	tmp;
	int		div;

	div = 1;
	nl = n;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl = nl * -1;
	}
	tmpnl = nl;
	while ((tmpnl = tmpnl / 10) >= 1)
		div = div * 10;
	while (div >= 10)
	{
		tmp = nl / div + 48;
		write(fd, &tmp, 1);
		nl = nl % div;
		div = div / 10;
	}
	tmp = nl + 48;
	write(fd, &tmp, 1);
}
