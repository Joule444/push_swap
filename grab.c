/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:20 by jules             #+#    #+#             */
/*   Updated: 2022/07/14 18:17:59 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grab_a(t_list *aim, t_list **stack_a)
{
	int	i;
	t_list	*elem;

	i = 0;
	elem = *stack_a;
	while (elem != aim)
	{
		elem = elem->next;
		i++;
	}
	if (i < ft_lstsize(*stack_a) / 2)
	{
		while (*stack_a != aim)
			rotate_a(stack_a);
	}
	else
		while (*stack_a != aim)
			rev_rotate_a(stack_a);
}