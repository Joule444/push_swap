/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:55:59 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/23 14:24:00 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
}

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->content >= (*stack_a)->next->content)
	{
		if (ft_lstlast(*stack_a)->content >= (*stack_a)->content)
			swap_a(stack_a);
		else if (ft_lstlast(*stack_a)->content >= (*stack_a)->next->content)
			rotate_a(stack_a);
		else
		{
			swap_a(stack_a);
			rev_rotate_a(stack_a);
		}
	}
	else
	{
		if (ft_lstlast(*stack_a)->content >= (*stack_a)->content)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
		else
			rev_rotate_a(stack_a);
	}
}
