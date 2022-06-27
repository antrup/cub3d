/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:58:50 by atruphem          #+#    #+#             */
/*   Updated: 2021/01/22 13:30:21 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			size_line(int ***map, int y)
{
	int		z;

	z = 0;
	while (map[0][y][z] != 9)
		z++;
	return (z - 1);
}

int			ft_count_line(char *buffer, int bsize)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < bsize)
	{
		if (buffer[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}
