/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_lim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:15 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/26 12:32:05 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_min(t_list *elem, t_list **stack)
{
	t_list	*check;

	check = *stack;
	while (check)
	{
		if (check->content < elem->content)
			return (0);
		check = check->next;
	}
	return (1);
}

int	is_stack_max(t_list *elem, t_list **stack)
{
	t_list	*check;

	check = *stack;
	while (check)
	{
		if (check->content > elem->content)
			return (0);
		check = check->next;
	}
	return (1);
}
