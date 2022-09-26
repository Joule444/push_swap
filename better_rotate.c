/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:17:11 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/26 13:04:10 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_rotate(t_list **stack, t_list *aim)
{
	t_list	*elem;
	int		dist_rot;
	int		dist_rev;

	elem = *stack;
	dist_rot = 0;
	dist_rev = 0;
	while (elem != aim)
	{
		dist_rot++;
		elem = elem->next;
	}
	elem = ft_lstlast(*stack);
	while (elem != aim)
	{
		dist_rev++;
		elem = lst_previous(stack, elem);
	}
	if (dist_rot - dist_rev <= 0)
		return (1);
	else
		return (-1);
}

int	better_rotate_portion(t_list **stack, int max)
{
	t_list	*elem;
	int		dist_rot;
	int		dist_rev;

	elem = *stack;
	dist_rot = 0;
	dist_rev = 0;
	while (!(elem->content < max))
	{
		dist_rot++;
		elem = elem->next;
	}
	elem = ft_lstlast(*stack);
	while (!(elem->content < max))
	{
		dist_rev++;
		elem = lst_previous(stack, elem);
	}
	if (dist_rot - dist_rev <= 0)
		return (1);
	else
		return (-1);
}

void	grab_elem_a(t_list *elem, t_list **stack_a)
{
	if (better_rotate(stack_a, elem) == 1)
		while ((*stack_a) != elem)
			rotate_a(stack_a);
	else
		while ((*stack_a) != elem)
			rev_rotate_a(stack_a);
}

void	grab_elem_b(t_list *elem, t_list **stack_b)
{
	if (better_rotate(stack_b, elem) == 1)
		while (*stack_b != elem)
			rotate_b(stack_b);
	else
		while (*stack_b != elem)
			rev_rotate_b(stack_b);
}
