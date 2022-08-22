/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:48:34 by jules             #+#    #+#             */
/*   Updated: 2022/08/22 22:45:20 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**stack_copy(t_list **stack)
{
	t_list	**copy;
	t_list	*elem;
	t_list	*elem_copy;

	copy = malloc(sizeof(t_list) * ft_lstsize(*stack));
	elem = *stack;
	while (elem)
	{
		elem_copy = ft_lstnew(elem->content);
		ft_lstadd_back(copy, elem_copy);
		elem = elem->next;
	}
	return (copy);
}

void	del_elem(t_list	**stack, t_list *aim)
{
	t_list	*elem;
	t_list	*tmp;

	elem = *stack;
	if (elem == aim)
	{
		*stack = elem->next;
		free(elem);
		return ;
	}
	while (elem->next != aim)
		elem = elem->next;
	tmp = elem->next->next;
	free(elem->next);
	elem->next = tmp;
}

int	get_mid(t_list **stack)
{
	int		i;
	int		size;
	int		*tab;
	t_list	*checker;
	t_list	*lower;

	i = 0;
	size = ft_lstsize(*stack);
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		lower = *stack;
		checker = *stack;
		while (checker)
		{
			if (checker->content < lower->content)
				lower = checker;
			checker = checker->next;
		}
		tab[i] = lower->content;
		del_elem(stack, lower);	
		i++;
	}
	return (free(stack), tab[ft_lstsize(*stack) / 2]);
}

void	split_stack(t_list **stack_a, t_list **stack_b, t_list *end)
{
	t_list	*elem;
	int		mid;

	elem = *stack_a;
	mid = get_mid(stack_copy(stack_a));
	while (elem != end)
	{
		if (elem->content < mid)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		elem = *stack_a;
	}
}