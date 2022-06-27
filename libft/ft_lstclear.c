/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:05:22 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:33:36 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || lst[0] == NULL)
		return ;
	current = lst[0];
	next = current->next;
	del(current->content);
	free(current);
	while (next != NULL)
	{
		current = next;
		next = current->next;
		del(current->content);
		free(current);
	}
	lst[0] = NULL;
}
