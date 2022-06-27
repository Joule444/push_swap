/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:49:21 by jules             #+#    #+#             */
/*   Updated: 2022/06/27 11:39:38 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack_a)
{
	int tmp;

	tmp = lst_index(stack_a, 0)->content;
	lst_index(stack_a, 0)->content = lst_index(stack_a, 1)->content;
	lst_index(stack_a, 1)->content = tmp;
}
