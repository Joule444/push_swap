/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:55:59 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/26 13:04:05 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->content >= (*stack_a)->next->content)
	{
		if (ft_lstlast(*stack_a)->content >= (*stack_a)->content)
			swap_a(stack_a);
		else if (ft_lstlast(*stack_a)->content >= (*stack_a)->next->content)
			rotate_a(stack_a);
		else
		{
			swap_a(stack_a);
			rev_rotate_a(stack_a);
		}
	}
	else
	{
		if (ft_lstlast(*stack_a)->content >= (*stack_a)->content)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
		else
			rev_rotate_a(stack_a);
	}
}

t_list	*get_min(t_list **stack)
{
	t_list	*elem;
	t_list	*min;

	elem = *stack;
	min = elem;
	while (elem)
	{
		if (elem->content < min->content)
			min = elem;
		elem = elem->next;
	}
	return (min);
}

void	grab_spot_a(t_list *aim, t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (!(elem->next && elem->content <= aim->content
			&& elem->next->content >= aim->content))
	{
		if (!elem->next)
			return ;
		elem = elem->next;
	}
	grab_elem_a(elem->next, stack);
}

void	find_spot_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = *stack_b;
	if (is_stack_min(elem, stack_a) || is_stack_max(elem, stack_a))
		grab_elem_a(get_min(stack_a), stack_a);
	else
		grab_spot_a(elem, stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (!check_sorted(stack_a))
		sort_3(stack_a);
	find_spot_a(stack_a, stack_b);
	find_spot_a(stack_a, stack_b);
	grab_elem_a(get_min(stack_a), stack_a);
}
