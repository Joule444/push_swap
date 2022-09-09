/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:05 by jules             #+#    #+#             */
/*   Updated: 2022/09/09 17:41:46 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_b(t_list **stack_a, t_list **stack_b)
{
	(*stack_b) = *stack_b;
	while ((*stack_b))
		push_a(stack_a, stack_b);
}

void	sort_elem(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
	while ((*stack_a) != end_a && (*stack_b) != end_b)
	{
		if ((*stack_a)->content > (*stack_a)->next->content && (*stack_b)->content < (*stack_b)->next->content)
			swap_s(stack_a, stack_b);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rotate_r(stack_a, stack_b);
	}
	while ((*stack_a) != end_a)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		rotate_a(stack_a);
	}
	while ((*stack_b) != end_b)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rotate_b(stack_b);
	}
}

t_list	*get_break(t_list **stack)
{
	t_list	*elem;
	t_list	*check;

	elem = *stack;
	while (elem->next)
	{
		check = elem->next;
		while (check)
		{
			if (check->content < elem->content)
				return (elem);
			check = check->next;
		}
		elem = elem->next;
	}
	return (elem);
}

t_list	*get_break_rev(t_list **stack)
{
	t_list	*elem;
	t_list	*check;

	elem = *stack;
	while (elem->next)
	{
		check = elem->next;
		while (check)
		{
			if (check->content > elem->content)
				return (elem);
			check = check->next;
		}
		elem = elem->next;
	}
	return (elem);
}

void	sort_elem_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*break_a;
	t_list	*break_b;

	break_a = get_break(stack_a);
	break_b = get_break_rev(stack_b);
	if (break_a == NULL || break_b == NULL)
		return ;
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	while (*stack_a != break_a && *stack_b != break_b)
	{
		if ((*stack_a)->content > (*stack_a)->next->content && (*stack_b)->content < (*stack_b)->next->content)
			swap_s(stack_a, stack_b);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rev_rotate_r(stack_a, stack_b);
	}
	while (*stack_a != break_a)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	while (*stack_b != break_b)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rev_rotate_b(stack_b);
	}
}

void	bubble_sort(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
	t_list	*bubble_a;
	t_list	*bubble_b;

	sort_elem(stack_a, stack_b, end_a, end_b);
	bubble_a = *stack_a;
	bubble_b = *stack_b;
	rotate_r(stack_a, stack_b);
	sort_elem_back(stack_a, stack_b);
	rotate_r(stack_a, stack_b);
	if (!check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)) || !check_sorted_rev(stack_b, *stack_b, ft_lstlast(*stack_b)))
		bubble_sort(stack_a, stack_b, lst_previous(stack_a, bubble_a), lst_previous(stack_b, bubble_b));
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
		return ;
	split_stack(stack_a, stack_b);
	bubble_sort(stack_a, stack_b, ft_lstlast(*stack_a), ft_lstlast(*stack_b));
	empty_b(stack_a, stack_b);
}