/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:33:58 by jules             #+#    #+#             */
/*   Updated: 2022/07/20 16:11:30 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = lst_index(stack_b, 1);
	ft_lstadd_front(stack_a, lst_index(stack_b, 0));
	*stack_b = elem;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem;

	elem = lst_index(stack_a, 1);
	ft_lstadd_front(stack_b, lst_index(stack_a, 0));
	*stack_a = elem;
	write(1, "pb\n", 3);
}