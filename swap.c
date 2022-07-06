/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:49:21 by jules             #+#    #+#             */
/*   Updated: 2022/07/06 15:07:05 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int tmp;

	tmp = lst_index(stack_a, 0)->content;
	lst_index(stack_a, 0)->content = lst_index(stack_a, 1)->content;
	lst_index(stack_a, 1)->content = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	int tmp;

	tmp = lst_index(stack_b, 0)->content;
	lst_index(stack_b, 0)->content = lst_index(stack_b, 1)->content;
	lst_index(stack_b, 1)->content = tmp;
	ft_printf("sb\n");
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
	ft_printf("ss\n");
}