/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:05 by jules             #+#    #+#             */
/*   Updated: 2022/08/22 21:02:23 by jules            ###   ########.fr       */
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

void	grab_start(t_list **stack_a, t_list **stack_b, t_list *bubble_a, t_list *bubble_b)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = *stack_a;
	elem_b = *stack_b;
	while (elem_a->content >= bubble_a->content && elem_b->content <= bubble_b->content)
	{
		rotate_r(stack_a, stack_b);
		elem_a = *stack_a;
		elem_b = *stack_b;
	}
	while (elem_a->content >= bubble_a->content)
	{
		rotate_a(stack_a);
		elem_a = *stack_a;
	}
	while (elem_b->content < bubble_b->content)
	{
		rotate_b(stack_b);
		elem_b = *stack_b;
	}
}

void	sort_elem(t_list **stack, t_list *end)
{
	t_list	*elem;

	elem = *stack;
	while (elem != end)
	{
		if (elem->content > elem->next->content)
			swap_a(stack);
		rotate_a(stack);
		elem = *stack;
	}
}

void	bubble_sort(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
	t_list	*bubble_a;
	t_list	*bubble_b;
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = *stack_a;
	elem_b = *stack_b;
	while (elem_a != end_a && elem_b != end_b)
	{
		if (elem_a->content > elem_a->next->content && elem_b->content < elem_b->next->content)
			swap_s(stack_a, stack_b);
		else if (elem_a->content > elem_a->next->content)
			swap_a(stack_a);
		else if (elem_b->content < elem_b->next->content)
			swap_b(stack_b);
		rotate_r(stack_a, stack_b);
		elem_a = *stack_a;
		elem_b = *stack_b;
	}
	sort_elem(stack_a, end_a);
	sort_elem(stack_b, end_b);
	bubble_a = *stack_a;
	bubble_b = *stack_b;
	grab_start(stack_a, stack_b, bubble_a, bubble_b);
	if (!check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)) || !check_sorted_rev(stack_b, *stack_b, ft_lstlast(*stack_b)))
		bubble_sort(stack_a, stack_b, lst_previous(stack_a, bubble_a), lst_previous(stack_b, bubble_b));
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
		return ;
	split_stack(stack_a, stack_b, ft_lstlast(*stack_a));
	bubble_sort(stack_a, stack_b, ft_lstlast(*stack_a), ft_lstlast(*stack_b));
	empty_b(stack_a, stack_b);
}