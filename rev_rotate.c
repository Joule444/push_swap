/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:21 by jules             #+#    #+#             */
/*   Updated: 2022/07/20 16:10:31 by jthuysba         ###   ########.fr       */
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
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
	write(1, "rrr\n", 4);
}