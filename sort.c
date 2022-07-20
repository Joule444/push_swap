/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:22:34 by jthuysba          #+#    #+#             */
/*   Updated: 2022/07/20 18:51:32 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem_b;

	elem_b = *stack_b;
	while (elem_b)
	{
		push_a(stack_a, stack_b);
		elem_b = *stack_b;
	}
}

int	check_sorted(t_list **stack, t_list *start, t_list *end)
{
	t_list	*elem;

	elem = *stack;
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

void	sort(t_list **stack_a, t_list **stack_b, t_list *pivot)
{
	t_list	*elem_a;
	int		size_b;

	elem_a = *stack_a;
	while (elem_a != pivot)
	{
		if (elem_a->content >= pivot->content)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		elem_a = *stack_a;
	}
	rotate_a(stack_a);
	size_b = ft_lstsize(*stack_b);
	empty_b(stack_a, stack_b);
	if (!check_sorted(stack_a, *stack_a, lst_index(stack_a, size_b - 1)))
		sort(stack_a, stack_b, lst_index(stack_a, size_b - 1));
}