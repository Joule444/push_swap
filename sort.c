/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:05:43 by jules             #+#    #+#             */
/*   Updated: 2022/07/07 18:34:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;
	int	pivot;
	int i;
	int ig;

	pivot = ft_lstlast(*stack_a)->content;
	ft_printf("Pivot=%d\n", pivot);
	i = 0;
	ig = 0;
	elem = *stack_a;
	while (elem)
	{
		if (elem->content <= pivot)
		{
			trade(ig, i, stack_a, stack_b);
			i++;
			ig++;
		}
		else
			i++;
		elem = elem->next;
	}
}