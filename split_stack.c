/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:48:34 by jules             #+#    #+#             */
/*   Updated: 2022/09/13 12:20:55 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_part(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*end;

	end = ft_lstlast(*stack_a);
	while ((*stack_a) != end)
	{
		if ((*stack_a)->content >= min && (*stack_a)->content < max)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	if ((*stack_a)->content >= min && (*stack_a)->content < max)
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
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
		split_presort(stack_a, stack_b, 24);
	else if (size >= 10)
		split_presort(stack_a, stack_b, 10);
}