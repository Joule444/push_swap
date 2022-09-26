/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:28:17 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/26 12:50:37 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grab_spot(t_list *aim, t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (!(elem->next && elem->content >= aim->content
			&& elem->next->content <= aim->content))
	{
		if (!elem->next)
			return ;
		elem = elem->next;
	}
	grab_elem_b(elem->next, stack);
}

t_list	*get_max(t_list **stack_b)
{
	t_list	*elem;
	t_list	*max;

	elem = *stack_b;
	max = elem;
	while (elem)
	{
		if (elem->content > max->content)
			max = elem;
		elem = elem->next;
	}
	return (max);
}

void	find_spot(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = *stack_a;
	if (ft_lstsize(*stack_b) >= 2)
	{
		if (is_stack_min(elem, stack_b) || is_stack_max(elem, stack_b))
			grab_elem_b(get_max(stack_b), stack_b);
		else
			grab_spot(elem, stack_b);
		push_b(stack_a, stack_b);
	}
	else
		push_b(stack_a, stack_b);
}
