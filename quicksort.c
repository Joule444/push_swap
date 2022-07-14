/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:43:19 by jules             #+#    #+#             */
/*   Updated: 2022/07/14 18:36:49 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_restart(t_list **stack_a, t_list *pivot)
{
	t_list	*elem;

	elem = *stack_a;
	while (elem->content > pivot->content)
	{
		rotate_a(stack_a);
		elem = *stack_a;
	}
}

int	check_pivot_min(t_list **stack_a, t_list *pivot)
{
	t_list	*elem;

	elem = *stack_a;
	while (elem != pivot)
	{
		if (elem->content <= pivot->content)
			return (0);
		elem = elem->next;
	}
	return (1);
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

void	quicksort(t_list *start, t_list *pivot, t_list **stack_a, t_list **stack_b)
{
	t_list	*elem_a;
	t_list	*elem_b;
	int	unused;
	int	size_b;

	elem_a = *stack_a;
	if (check_pivot_min(stack_a, pivot))
		rev_rotate_a(stack_a);
	else
	{
		while (elem_a != start)
		{
			rotate_a(stack_a);
			elem_a = *stack_a;
		}
		while (elem_a != pivot)
		{
			if (elem_a->content > pivot->content)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			elem_a = *stack_a;
		}
		rotate_a(stack_a);
		size_b = ft_lstsize(*stack_b);
		elem_b = *stack_b;
		while (elem_b)
		{
			push_a(stack_a, stack_b);
			elem_b = *stack_b;
		}
		get_restart(stack_a, pivot);
	}
	if (!check_sorted(stack_a, *stack_a, lst_previous(stack_a, pivot)))
		quicksort(*stack_a, lst_previous(stack_a, pivot), stack_a, stack_b);
	if (!check_sorted(stack_a, pivot, ft_lstlast(*stack_a)))
		quicksort(pivot, ft_lstlast(*stack_a), stack_a, stack_b);
}