/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fonctions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:51:53 by jules             #+#    #+#             */
/*   Updated: 2022/09/13 12:33:50 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_index(t_list **list, int index)
{
	t_list	*elem;

	elem = *list;
	while (index > 0)
	{
		elem = elem->next;
		index--;
	}
	return (elem);
}

int	ft_lstsize(t_list *lst)
{
	int	a;

	a = 0;
	if (lst)
	{
		while (lst)
		{
			a++;
			lst = lst->next;
		}
	}
	return (a);
}

t_list	*lst_previous(t_list **stack, t_list *aim)
{
	t_list	*elem;

	elem = *stack;
	if (elem == aim)
		return (*stack);
	while (elem->next != aim)
		elem = elem->next;
	return (elem);
}
