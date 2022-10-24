/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:24:17 by jthuysba          #+#    #+#             */
/*   Updated: 2022/10/24 16:41:30 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_portion(t_list **stack, int max)
{
	t_list	*elem;

	elem = *stack;
	while (elem)
	{
		if (elem->content < max)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, int max)
{
	while (find_portion(stack_a, max))
	{
		if (better_rotate_portion(stack_a, max) == 1)
			while (!((*stack_a)->content < max))
				rotate_a(stack_a);
		else
			while (!((*stack_a)->content < max))
				rev_rotate_a(stack_a);
		find_spot(stack_a, stack_b);
	}
}

void	empty_b(t_list **stack_a, t_list **stack_b)
{
	(*stack_b) = *stack_b;
	while ((*stack_b))
		push_a(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	size;
	int	x;
	int	chunks;

	tab = get_tab(stack_copy(stack_a));
	size = ft_lstsize(*stack_a) - 1;
	x = 1;
	if (size >= 200)
		chunks = 11;
	else
		chunks = 5;
	while (x <= chunks)
	{
		sort_chunk(stack_a, stack_b, tab[(x * size) / chunks]);
		x++;
	}
	find_spot(stack_a, stack_b);
	empty_b(stack_a, stack_b);
	free(tab);
}
