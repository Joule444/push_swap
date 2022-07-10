/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:05:43 by jules             #+#    #+#             */
/*   Updated: 2022/07/10 18:07:37 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack, int start, int end)
{
	int	i;
	t_list	*elem;

	i = 0;
	elem = *stack;
	while (i < start)
	{
		elem = elem->next;
		i++;
	}
	while (i < end)
	{
		if (elem->content > elem->next->content)
			return (0);
		elem = elem->next;
		i++;
	}
	return (1);
}

void	sort(t_list **stack_a, t_list **stack_b, int start, t_list *pivot)
{
	t_list	*elem;
	int i;
	int ig;
	
	i = 0;
	ig = 0;
	elem = *stack_a;
	while (i < start)
	{
		elem = elem->next;
		i++;
		ig++;
	}
	while (elem != pivot)
	{
		if (elem->content <= pivot->content)
		{
			trade(ig, i, stack_a, stack_b);
			i++;
			ig++;
		}
		else
			i++;
		elem = elem->next;
	}
	trade(ig, i, stack_a, stack_b);
	if (!check_sorted(stack_a, 0, ig)) //en dessous du pivot
		sort(stack_a, stack_b, 0, lst_index(stack_a, ig - 1));
	if (!check_sorted(stack_a, ig, i)) //au dessus du pivot
		sort(stack_a, stack_b, ig, lst_index(stack_a, i));
}