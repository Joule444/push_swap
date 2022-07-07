/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:06:20 by jules             #+#    #+#             */
/*   Updated: 2022/07/07 18:34:53 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trade(int a, int b, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (a == b)
		return ;
	while (i < a)
	{
		rotate_a(stack_a);
		i++;
	}
	push_b(stack_a, stack_b);
	while (i < b - 1)
	{
		rotate_a(stack_a);
		i++;
	}
	push_b(stack_a, stack_b);
	swap_b(stack_b);
	push_a(stack_a, stack_b);
	while (i < ft_lstsize(*stack_a) + a)
	{
		rotate_a(stack_a);
		i++;
	}
	push_a(stack_a, stack_b);
	while (i < 2 * ft_lstsize(*stack_a) - 1)
	{
		rotate_a(stack_a);
		i++;
	}
}