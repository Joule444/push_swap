/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:51:53 by jules             #+#    #+#             */
/*   Updated: 2022/06/17 15:56:06 by jules            ###   ########.fr       */
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