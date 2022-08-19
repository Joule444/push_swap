/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:05 by jules             #+#    #+#             */
/*   Updated: 2022/08/19 18:31:35 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack, t_list *start, t_list *end)
{
	t_list	*elem;

	elem = *stack;
	if (end <= 0 || start < 0)
		return (1);
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

int	get_mid(t_list **stack_a)
{
	t_list *elem;
	int		sum;

	elem = *stack_a;
	sum = 0;
	while (elem)
	{
		sum += elem->content;
		elem = elem->next;
	}
	return (sum / ft_lstsize(*stack_a));
}

void	split_stack(t_list **stack_a, t_list **stack_b, t_list *end)
{
	t_list	*elem;
	int		mid;

	elem = *stack_a;
	mid = get_mid(stack_a);
	while (elem != end)
	{
		if (elem->content < mid)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		elem = *stack_a;
	}
}

void	grab_start(t_list **stack_a, t_list **stack_b, t_list *bubble_a, t_list *bubble_b)
{

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
	bubble_a = *stack_a;
	bubble_b = *stack_b;
	grab_start(stack_a, stack_b, bubble_a, bubble_b);
	// if (!check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
	// 	bubble_sort(stack_a, stack_b, lst_previous(stack_a, bubble_a));
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
		return ;
	split_stack(stack_a, stack_b, ft_lstlast(*stack_a));
	bubble_sort(stack_a, stack_b, ft_lstlast(*stack_a), ft_lstlast(*stack_a));
	empty_b(stack_a, stack_b);
}