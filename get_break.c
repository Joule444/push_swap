/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:25:39 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/20 12:56:20 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	silent_rev_rotate(t_list **stack)
{
	t_list	*elem1;
	t_list	*elemprelast;
	t_list	*elemlast;

	elem1 = lst_index(stack, 0);
	elemprelast = lst_index(stack, ft_lstsize(elem1) - 2);
	elemlast = ft_lstlast(elem1);
	elemlast->next = elem1;
	elemprelast->next = NULL;
	*stack = elemlast;
}

t_list	*get_top(t_list **stack)
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

t_list	*get_bottom(t_list **stack)
{
	t_list	*start;
	t_list	*elem;
	t_list	*check;

	start = *stack;
	while (ft_lstlast(*stack)->content > (*stack)->content)
		silent_rev_rotate(stack);
	elem = ft_lstlast(*stack);
	while (elem != start)
	{
		check = lst_previous(stack, elem);
		while (check != start)
		{
			if (check->content < elem->content)
			{
				while ((*stack) != start)
					silent_rotate(stack);
				return (elem);
			}
			check = lst_previous(stack, check);
		}
		elem = lst_previous(stack, elem);
	}
	elem = ft_lstlast(*stack);
	while ((*stack) != start)
		silent_rotate(stack);
	return (elem);
}