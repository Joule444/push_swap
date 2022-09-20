/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:48:34 by jules             #+#    #+#             */
/*   Updated: 2022/09/20 13:55:51 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_portion(t_list **stack, int min, int max)
{
	t_list	*elem;

	elem = *stack;
	while (elem)
	{
		if (elem->content >= min && elem->content < max)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void	push_part(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while (find_portion(stack_a, min, max))
	{
		if (better_rotate(stack_a, min, max) > 0)
		{
			while (!((*stack_a)->content >= min && (*stack_a)->content < max))
				rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else
		{
			while (!((*stack_a)->content >= min && (*stack_a)->content < max))
				rev_rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
	}
}

void	split_presort(t_list **stack_a, t_list **stack_b, int div)
{
	int				i;
	int				size;
	int				*tab;
	unsigned int	size_diff;

	i = 0;
	size = ft_lstsize(*stack_a);
	tab = get_tab(stack_copy(stack_a));
	while (i < div - 1)
	{
		push_part(stack_a, stack_b, tab[(i * size) / div], tab[((i + 1) * size) / div]);
		i++;
	}
	size_diff = ft_lstsize(*stack_a) - ft_lstsize(*stack_b);
	while (size_diff > 1)
	{
		push_a(stack_a, stack_b);
		size_diff = ft_lstsize(*stack_a) - ft_lstsize(*stack_b);
	}
}

void	split_stack(t_list **stack_a, t_list **stack_b)
{
	int				size;

	size = ft_lstsize(*stack_a);
	if (size >= 300)
		split_presort(stack_a, stack_b, 26);
	else if (size >= 10)
		split_presort(stack_a, stack_b, 10);
}