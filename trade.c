/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:20 by jules             #+#    #+#             */
/*   Updated: 2022/07/13 12:39:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grab_a(t_list *aim, t_list **stack_a)
{
	int	i;
	t_list	*elem;

	i = 0;
	elem = *stack_a;
	while (elem != aim)
	{
		elem = elem->next;
		i++;
	}
	if (i < ft_lstsize(*stack_a) / 2)
	{
		while (*stack_a != aim)
			rotate_a(stack_a);
	}
	else
		while (*stack_a != aim)
			rev_rotate_a(stack_a);
}

void	trade(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b)
{
	t_list	*elem_next_a;
	//t_list	*elem_0;

	elem_next_a = a->next;
	//elem_0 = *stack_a;
	if (a == b)
		return ;
	grab_a(a, stack_a);
	push_b(stack_a, stack_b);
	grab_a(b, stack_a);
	push_b(stack_a, stack_b);
	swap_b(stack_b);
	push_a(stack_a, stack_b);
	grab_a(elem_next_a, stack_a);
	push_a(stack_a, stack_b);
	//grab_a(elem_0, stack_a);
}