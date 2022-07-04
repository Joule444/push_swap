/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:33:58 by jules             #+#    #+#             */
/*   Updated: 2022/07/04 15:52:59 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	ft_lstadd_front(stack_a, lst_index(stack_b, 0));
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	ft_lstadd_front(stack_b, lst_index(stack_a, 0));
}