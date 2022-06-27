/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:40:37 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/17 12:40:59 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_color(char *color, char value, int index)
{
	if (index == 0)
		*(color + 2) = value;
	if (index == 1)
		*(color + 1) = value;
	if (index == 3)
		*(color) = value;
}
