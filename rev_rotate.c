/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:21 by jules             #+#    #+#             */
/*   Updated: 2022/07/06 15:07:20 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*elem1;
	t_list	*elemprelast;
	t_list	*elemlast;

	elem1 = lst_index(stack_a, 0);
	elemprelast = lst_index(stack_a, ft_lstsize(elem1) - 2);
	elemlast = ft_lstlast(elem1);
	elemlast->next = elem1;
	elemprelast->next = NULL;
	*stack_a = elemlast;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*elem1;
	t_list	*elemprelast;
	t_list	*elemlast;

	elem1 = lst_index(stack_b, 0);
	elemprelast = lst_index(stack_b, ft_lstsize(elem1) - 2);
	elemlast = ft_lstlast(elem1);
	elemlast->next = elem1;
	elemprelast->next = NULL;
	*stack_b = elemlast;
	ft_printf("rrb\n");
}

void	rev_rotate_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem1;
	t_list	*elemprelast;
	t_list	*elemlast;

	elem1 = lst_index(stack_a, 0);
	elemprelast = lst_index(stack_a, ft_lstsize(elem1) - 2);
	elemlast = ft_lstlast(elem1);
	elemlast->next = elem1;
	elemprelast->next = NULL;
	*stack_a = elemlast;
	elem1 = lst_index(stack_b, 0);
	elemprelast = lst_index(stack_b, ft_lstsize(elem1) - 2);
	elemlast = ft_lstlast(elem1);
	elemlast->next = elem1;
	elemprelast->next = NULL;
	*stack_b = elemlast;
	ft_printf("rrr\n");
}