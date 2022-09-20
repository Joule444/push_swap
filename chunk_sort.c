/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:24:17 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/20 17:50:42 by jthuysba         ###   ########.fr       */
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

t_list	*get_min(t_list **stack_b)
{
	t_list	*elem;
	t_list	*min;

	elem = *stack_b;
	min = elem;
	while (elem)
	{
		if (elem->content < min->content)
			min = elem;
		elem = elem->next;
	}
	return (min);
}

void	grab_spot(t_list *aim, t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (!(elem->next && elem->content <= aim->content && elem->next->content >= aim->content)
		|| !(elem->next) && elem->content <= aim->content && (*stack)->content >= aim->content)
		elem = elem->next;
	grab_elem_b(elem->next, stack);
}

void	find_spot(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = *stack_a;
	if (ft_lstsize(*stack_b) >= 2)
	{
		if (is_stack_min(elem, stack_b) || is_stack_max(elem, stack_b))
			grab_elem_b(get_min(stack_b), stack_b);
		else
			grab_spot(elem, stack_b);
		push_b(stack_a, stack_b);
	}
	else
		push_b(stack_a, stack_b);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	size;

	tab = get_tab(stack_copy(stack_a));
	size = ft_lstsize(*stack_a);
	while (find_portion(stack_a, tab[0], tab[size / 5]))
	{
		if (better_rotate_portion(stack_a, tab[0], tab[size / 5]) == 1)
			while (!((*stack_a)->content >= tab[0] && (*stack_a)->content < tab[size / 5]))
				rotate_a(stack_a);
		else
			while (!((*stack_a)->content >= tab[0] && (*stack_a)->content < tab[size / 5]))
				rev_rotate_a(stack_a);
		find_spot(stack_a, stack_b);
	}
	free(tab);
}