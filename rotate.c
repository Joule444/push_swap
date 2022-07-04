/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:58:56 by jules             #+#    #+#             */
/*   Updated: 2022/07/04 16:29:17 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elemlast;

	elem1 = lst_index(stack_a, 0);
	elem2 = lst_index(stack_a, 1);
	elemlast = ft_lstlast(elem1);
	elem1->next = NULL;
	elemlast->next = elem1;
	*stack_a = elem2; 
	ft_printf("ra");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elemlast;

	elem1 = lst_index(stack_b, 0);
	elem2 = lst_index(stack_b, 1);
	elemlast = ft_lstlast(elem1);
	elem1->next = NULL;
	elemlast->next = elem1;
	*stack_b = elem2; 
	ft_printf("rb");
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elemlast;

	elem1 = lst_index(stack_a, 0);
	elem2 = lst_index(stack_a, 1);
	elemlast = ft_lstlast(elem1);
	elem1->next = NULL;
	elemlast->next = elem1;
	*stack_a = elem2; 
	elem1 = lst_index(stack_b, 0);
	elem2 = lst_index(stack_b, 1);
	elemlast = ft_lstlast(elem1);
	elem1->next = NULL;
	elemlast->next = elem1;
	*stack_b = elem2;
	ft_printf("rr");
}