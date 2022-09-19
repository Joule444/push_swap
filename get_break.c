/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:25:39 by jthuysba          #+#    #+#             */
/*   Updated: 2022/09/19 12:16:57 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_break(t_list **stack)
{
	t_list	*elem;
	t_list	*check;

	elem = *stack;
	while (elem->next)
	{
		check = elem->next;
		while (check)
		{
			if (check->content < elem->content)
				return (elem);
			check = check->next;
		}
		elem = elem->next;
	}
	return (elem);
}
