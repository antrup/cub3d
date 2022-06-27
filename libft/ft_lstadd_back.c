/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:42:59 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/21 18:43:41 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*current;

	if (alst == NULL)
		return ;
	if (alst[0] == NULL)
	{
		alst[0] = new;
		return ;
	}
	current = alst[0];
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
