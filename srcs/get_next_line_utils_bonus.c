/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:39:45 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/27 00:24:18 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int		ft_initialize(int fd, t_fdparam *config, char **line)
{
	if ((config->i[1] = read(fd, config->buffer, BUFFER_SIZE)) == 0)
	{
		line[0][0] = '\0';
		return (1);
	}
	if (config->i[1] == -1)
	{
		free(line[0]);
		line[0] = NULL;
		return (-1);
	}
	config->i[0] = 0;
	return (0);
}

char	*ft_realloc(int size, char **line)
{
	char	*temp;
	int		i;

	if (!(temp = malloc((sizeof(char) * BUFFER_SIZE) * size + 1)))
		return (NULL);
	i = 0;
	while (i < (BUFFER_SIZE * (size - 1)))
	{
		temp[i] = line[0][i];
		i++;
	}
	if (size > 1)
		free(line[0]);
	line[0] = temp;
	return (line[0]);
}

int		ft_resize(char **line, int j, t_fdparam *config, t_fdparam *root)
{
	int		size;

	if (BUFFER_SIZE != 0)
		size = (j / BUFFER_SIZE) + 1;
	else
		size = 0;
	if (!(ft_realloc(size, line)))
	{
		ft_clean(&config, &root);
		return (-1);
	}
	return (0);
}

int		ft_loadbuffer(int fd, t_fdparam *config, int *i)
{
	if ((i[1] = read(fd, config->buffer, BUFFER_SIZE)) == 0)
		return (1);
	i[0] = 0;
	return (0);
}

int		ft_reader(t_fdparam *config, char **line, int fd, t_fdparam *root)
{
	int		eofc;
	int		j;

	eofc = 0;
	j = 0;
	while (config->buffer[config->i[0]] != '\n')
	{
		if (config->i[1] == 0)
			if ((eofc = ft_loadbuffer(fd, config, config->i) == 1))
				break ;
		line[0][j] = config->buffer[config->i[0]];
		(config->i[0])++;
		j++;
		(config->i[1])--;
		if (config->i[1] == 0)
			if ((eofc = ft_loadbuffer(fd, config, config->i) == 1))
				break ;
		if (BUFFER_SIZE != 0)
			if (j % BUFFER_SIZE == 0)
				if ((ft_resize(line, j, config, root)) == -1)
					return (-1);
	}
	line[0][j] = '\0';
	return (eofc);
}
