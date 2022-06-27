/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:08:50 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:15:14 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_creastr(char *result, long n, int count, int sign)
{
	result[count + sign] = '\0';
	while (n / 10 >= 1)
	{
		result[count + sign - 1] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	result[count + sign - 1] = n % 10 + 48;
	if (sign)
		result[0] = '-';
}

char			*ft_itoa(int n)
{
	int		sign;
	long	tmp;
	int		count;
	char	*result;
	long	nl;

	count = 1;
	sign = 0;
	nl = n;
	if (nl < 0)
	{
		sign = 1;
		nl = nl * -1;
	}
	tmp = nl;
	while (tmp / 10 >= 1)
	{
		count++;
		tmp = tmp / 10;
	}
	if (!(result = malloc(sizeof(char) * (count + sign + 1))))
		return (NULL);
	ft_creastr(result, nl, count, sign);
	return (result);
}
