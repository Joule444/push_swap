/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:05 by jules             #+#    #+#             */
/*   Updated: 2022/09/19 17:19:53 by jthuysba         ###   ########.fr       */
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
		if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_b)->content < (*stack_b)->next->content)
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

void	sort_elem_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*break_a;
	t_list	*break_b;

	break_a = get_break(stack_a);
	break_b = get_break_rev(stack_b);
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	while (*stack_a != break_a && *stack_b != break_b)
	{
		if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_b)->content < (*stack_b)->next->content)
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
	if (!check_sorted(stack_a, *stack_a, bubble_a)
		|| !check_sorted_rev(stack_b, *stack_b, bubble_b))
		bubble_sort(stack_a, stack_b, bubble_a, bubble_b);
}

// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	if (check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
// 		return ;
// 	split_stack(stack_a, stack_b);
// 	bubble_sort(stack_a, stack_b, ft_lstlast(*stack_a), ft_lstlast(*stack_b));
// 	rotate_r(stack_a, stack_b);
// 	empty_b(stack_a, stack_b);
// }

void	silent_rotate(t_list **stack)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elemlast;

	elem1 = lst_index(stack, 0);
	elem2 = lst_index(stack, 1);
	elemlast = ft_lstlast(elem1);
	elem1->next = NULL;
	elemlast->next = elem1;
	*stack = elem2;
}

t_list	*get_break_rev(t_list **stack)
{
	t_list	*start;
	t_list	*elem;
	t_list	*check;

	start = *stack;
	while ((*stack)->content <= start->content)
		silent_rotate(stack);
	elem = *stack;
	while (elem->next)
	{
		check = elem->next;
		while (check)
		{
			if (check->content > elem->content)
			{
				while ((*stack) != start)
					silent_rotate(stack);
				return (elem);
			}
			check = check->next;
		}
		elem = elem->next;
	}
	elem = *stack;
	while ((*stack) != start)
		silent_rotate(stack);
	return (elem);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, t_list *end)
{
	t_list	*start;
	t_list	*bubble;

	if (check_sorted_rev(stack_b, *stack_b, end))
		return ;
	while (*stack_b != end)
	{
		if ((*stack_b)->content < (*stack_b)->next->content && (*stack_a)->content > (*stack_a)->next->content)
			swap_s(stack_a, stack_b);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rotate_r(stack_a, stack_b);
	}
	bubble = *stack_b;
	start = get_break_rev(stack_b);
	rev_rotate_r(stack_a, stack_b);
	rev_rotate_r(stack_a, stack_b);
	while (*stack_b != start)
	{
		if ((*stack_b)->content < (*stack_b)->next->content && (*stack_a)->content > (*stack_a)->next->content)
			swap_s(stack_a, stack_b);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		rev_rotate_r(stack_a, stack_b);
	}
	if ((*stack_b)->content < (*stack_b)->next->content)
		swap_b(stack_b);
	if (!(check_sorted_rev(stack_b, *stack_b, bubble)))
		sort_stack(stack_a, stack_b, lst_previous(stack_b, bubble));
}

void	sort_portion(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*start;

	start = *stack_b;
	push_part(stack_a, stack_b, min, max);
	sort_stack(stack_a, stack_b, lst_previous(stack_b, start));
	while (lst_previous(stack_b, *stack_b)->content >= (*stack_b)->content)
		rev_rotate_b(stack_b);
}

void	double_sort(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b)
{
	sort_elem(stack_a, stack_b, end_a, end_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		*tab;
	int		size;
	int		x;

	x = 0;
	if (check_sorted(stack_a, *stack_a, ft_lstlast(*stack_a)))
		return ;
	tab = get_tab(stack_copy(stack_a));
	size = ft_lstsize(*stack_a);
	while (x < 10)
	{
		sort_portion(stack_a, stack_b, tab[(x * size) / 12], tab[((x + 1) * size) / 12]);
		x++;
	}
	push_part(stack_a, stack_b, tab[(x * size) / 12], tab[((x + 1) * size) / 12]);
	double_sort(stack_a, stack_b);
}
