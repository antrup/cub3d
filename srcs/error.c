/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:56:37 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/23 22:34:10 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	error_f_c(int ind)
{
	if (ind == 1)
		ft_putstr_fd("Error\n Illegal floor color\n", 2);
	else
		ft_putstr_fd("Error\n Illegal ceiling color\n", 2);
	return (2);
}

int	error_dp(void)
{
	ft_putstr_fd("Display connection error\n", 2);
	return (2);
}

int	error_gen(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (2);
}
