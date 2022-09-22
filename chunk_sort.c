/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:24:17 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/22 19:31:44 by jules            ###   ########.fr       */
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

int	is_stack_min(t_list *elem, t_list **stack)
{
	t_list	*check;

	check = *stack;
	while (check)
	{
		if (check->content < elem->content)
			return (0);
		check = check->next;
	}
	return (1);
}

int	is_stack_max(t_list *elem, t_list **stack)
{
	t_list	*check;

	check = *stack;
	while (check)
	{
		if (check->content > elem->content)
			return (0);
		check = check->next;
	}
	return (1);
}

t_list	*get_max(t_list **stack_b)
{
	t_list	*elem;
	t_list	*max;

	elem = *stack_b;
	max = elem;
	while (elem)
	{
		if (elem->content > max->content)
			max = elem;
		elem = elem->next;
	}
	return (max);
}

void	grab_spot(t_list *aim, t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (!(elem->next && elem->content >= aim->content && elem->next->content <= aim->content))
	{
		if (!elem->next)
			return ;
		elem = elem->next;
	}
	grab_elem_b(elem->next, stack);
}

void	find_spot(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = *stack_a;
	if (ft_lstsize(*stack_b) >= 2)
	{
		if (is_stack_min(elem, stack_b) || is_stack_max(elem, stack_b))
			grab_elem_b(get_max(stack_b), stack_b);
		else
			grab_spot(elem, stack_b);
		push_b(stack_a, stack_b);
	}
	else
		push_b(stack_a, stack_b);
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
	int x;
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