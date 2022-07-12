/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:05:43 by jules             #+#    #+#             */
/*   Updated: 2022/07/12 18:22:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_list **stack_a, t_list **stack_b, t_list *start, t_list *pivot)
{
	t_list *i;
	t_list *ig;
	
	i = *stack_a;
	ig = *stack_a;
	while (i != start)
	{
		i = i->next;
		ig = ig->next;
	}
	while (i != pivot)
	{
		if (i->content <= pivot->content)
		{
			trade(ig, i, stack_a, stack_b);
			i = i->next;
			ig = ig->next;
		}
		else
			i = i->next;
	}
	trade(ig, i, stack_a, stack_b);
	if (!check_sorted(stack_a, 0, ig)) //en dessous du pivot
		sort(stack_a, stack_b, 0, ig);
	if (!check_sorted(stack_a, ig, i)) //au dessus du pivot
		sort(stack_a, stack_b, ig, i);
}