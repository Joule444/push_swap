/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:49:59 by jules             #+#    #+#             */
/*   Updated: 2022/08/22 20:50:17 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack, t_list *start, t_list *end)
{
	t_list	*elem;

	elem = *stack;
	if (end <= 0 || start < 0)
		return (1);
	while (elem != start)
		elem = elem->next;
	while (elem != end)
	{
		if (elem->content > elem->next->content)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int	check_sorted_rev(t_list **stack, t_list *start, t_list *end)
{
	t_list	*elem;

	elem = *stack;
	if (end <= 0 || start < 0)
		return (1);
	while (elem != start)
		elem = elem->next;
	while (elem != end)
	{
		if (elem->content < elem->next->content)
			return (0);
		elem = elem->next;
	}
	return (1);
}