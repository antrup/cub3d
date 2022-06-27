/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:43:26 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/27 00:21:19 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int			ft_clean(t_fdparam **config, t_fdparam **root)
{
	t_fdparam		*current;

	if (root[0] == config[0])
		root[0] = (config[0])->next;
	else
	{
		current = root[0];
		while (current->next != config[0])
			current = current->next;
		current->next = (config[0])->next;
	}
	free((config[0])->buffer);
	free(config[0]);
	config[0] = NULL;
	return (1);
}

t_fdparam	*ft_findconfig(int fd, t_fdparam *root)
{
	if (!root)
		return (NULL);
	if (fd == root->fd)
		return (root);
	while ((root = root->next))
	{
		if (fd == root->fd)
			return (root);
	}
	return (NULL);
}

t_fdparam	*ft_initconfig(int fd, t_fdparam **root)
{
	t_fdparam	*new;
	t_fdparam	*current;

	if (!(new = malloc(sizeof(t_fdparam))))
		return (NULL);
	if (!(new->buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (NULL);
	new->next = NULL;
	new->fd = fd;
	new->i[0] = 0;
	new->i[1] = 0;
	new->eofc = 0;
	if (root[0] == NULL)
	{
		root[0] = new;
		return (new);
	}
	current = root[0];
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (new);
}

int			get_next_line(int fd, char **line)
{
	static	t_fdparam	*root = NULL;
	t_fdparam			*config;

	if (!(config = ft_findconfig(fd, root)))
		if (!(config = ft_initconfig(fd, &root)))
			return (-1);
	if (line == NULL || BUFFER_SIZE == 0 || !(ft_realloc(1, line)))
		return (-1);
	if (config->i[1] == 0)
		if ((config->eofc = ft_initialize(fd, config, line)) == -1)
			if (ft_clean(&config, &root))
				return (-1);
	if (config->eofc)
		if (ft_clean(&config, &root))
			return (0);
	if ((config->eofc = ft_reader(config, line, fd, root)) == -1)
		return (-1);
	(config->i[0])++;
	(config->i[1])--;
	if (config->eofc)
		if (ft_clean(&config, &root))
			return (0);
	return (1);
}
