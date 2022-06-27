/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:34:01 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/23 17:33:53 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_newlst(t_list *lst, t_list *newlist, void *(*f)(void *))
{
	t_list	*newelem;

	while ((lst = lst->next))
	{
		if (!(newelem = malloc(sizeof(t_list))))
			return (-1);
		if (!(newelem->content = f(lst->content)))
		{
			free(newelem);
			return (-1);
		}
		newlist->next = newelem;
		newlist = newelem;
		newlist->next = NULL;
	}
	return (0);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*first;

	if (lst == NULL || !(first = malloc(sizeof(t_list))))
		return (NULL);
	if (!(first->content = f(lst->content)))
	{
		free(first);
		return (NULL);
	}
	first->next = NULL;
	if (ft_newlst(lst, first, f) == -1)
	{
		ft_lstclear(&first, del);
		return (NULL);
	}
	return (first);
}
