/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:49:21 by jules             #+#    #+#             */
/*   Updated: 2022/07/20 16:09:45 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int tmp;

	tmp = lst_index(stack_a, 0)->content;
	lst_index(stack_a, 0)->content = lst_index(stack_a, 1)->content;
	lst_index(stack_a, 1)->content = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	int tmp;

	tmp = lst_index(stack_b, 0)->content;
	lst_index(stack_b, 0)->content = lst_index(stack_b, 1)->content;
	lst_index(stack_b, 1)->content = tmp;
	write(1, "sb\n", 3);
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	int tmp;

	tmp = lst_index(stack_a, 0)->content;
	lst_index(stack_a, 0)->content = lst_index(stack_a, 1)->content;
	lst_index(stack_a, 1)->content = tmp;
	tmp = lst_index(stack_b, 0)->content;
	lst_index(stack_b, 0)->content = lst_index(stack_b, 1)->content;
	lst_index(stack_b, 1)->content = tmp;
	write(1, "ss\n", 3);
}