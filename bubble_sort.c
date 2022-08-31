/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:05 by jules             #+#    #+#             */
/*   Updated: 2022/08/29 21:25:26 by jules            ###   ########.fr       */
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

void	sort_elem(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
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
	while (elem_a != end_a)
	{
		if (elem_a->content > elem_a->next->content)
			swap_a(stack_a);
		rotate_a(stack_a);
		elem_a = *stack_a;
	}
	while (elem_b != end_b)
	{
		if (elem_b->content < elem_b->next->content)
			swap_b(stack_b);
		rotate_b(stack_b);
		elem_b = *stack_b;
	}
}

void	sort_elem_back(t_list **stack_a, t_list **stack_b, t_list *bubble_a, t_list *bubble_b)
{
	t_list	*elem_a;
	t_list	*elem_b;
	
	elem_a = *stack_a;
	elem_b = *stack_b;
	while (elem_a != bubble_a && elem_b != bubble_b && elem_a->content <= bubble_a->content && elem_b->content >= bubble_b->content)
	{
		if (elem_a->content > elem_a->next->content && elem_b->content < elem_b->next->content)
			swap_s(stack_a, stack_b);
		else if (elem_a->content > elem_a->next->content)
			swap_a(stack_a);
		else if (elem_b->content < elem_b->next->content)
			swap_b(stack_b);
		rev_rotate_r(stack_a, stack_b);
		elem_a = *stack_a;
		elem_b = *stack_b;
	}
	while (elem_a != bubble_a && elem_a->content <= bubble_a->content)
	{
		if (elem_a->content > elem_a->next->content)
			swap_a(stack_a);
		rev_rotate_a(stack_a);
		elem_a = *stack_a;
	}
	while (elem_b != bubble_b && elem_b->content >= bubble_b->content)
	{
		if (elem_b->content < elem_b->next->content)
			swap_b(stack_b);
		rev_rotate_b(stack_b);
		elem_b = *stack_b;
	}
}

void	bubble_sort(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
	t_list	*bubble_a;
	t_list	*bubble_b;
	
	sort_elem(stack_a, stack_b, end_a, end_b);
	bubble_a = *stack_a;
	bubble_b = *stack_b;
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	sort_elem_back(stack_a, stack_b, bubble_a, bubble_b);
	rotate_r(stack_a, stack_b);
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