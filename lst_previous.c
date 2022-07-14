/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_previous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:41:46 by jules             #+#    #+#             */
/*   Updated: 2022/07/14 18:42:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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