/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:48:34 by jules             #+#    #+#             */
/*   Updated: 2022/09/09 13:55:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**stack_copy(t_list **stack)
{
	t_list	**copy;
	t_list	*elem;
	t_list	*elem_copy;

	copy = malloc(sizeof(t_list) * ft_lstsize(*stack));
	elem = *stack;
	while (elem)
	{
		elem_copy = ft_lstnew(elem->content);
		ft_lstadd_back(copy, elem_copy);
		elem = elem->next;
	}
	return (copy);
}

void	del_elem(t_list	**stack, t_list *aim)
{
	t_list	*elem;
	t_list	*tmp;

	elem = *stack;
	if (elem == aim)
	{
		*stack = elem->next;
		free(elem);
		return ;
	}
	while (elem->next != aim)
		elem = elem->next;
	tmp = elem->next->next;
	free(elem->next);
	elem->next = tmp;
}

int	*get_mid(t_list **stack)
{
	int		i;
	int		size;
	int		*tab;
	t_list	*checker;
	t_list	*lower;

	i = 0;
	size = ft_lstsize(*stack);
	tab = malloc(sizeof(int) * size); 
	while (i < size)
	{
		lower = *stack;
		checker = *stack;
		while (checker)
		{
			if (checker->content < lower->content)
				lower = checker;
			checker = checker->next;
		}
		tab[i] = lower->content;
		del_elem(stack, lower);	
		i++;
	}
	return (free(stack), tab);
}

void	push_part(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*end;

	end = ft_lstlast(*stack_a);
	while ((*stack_a) != end)
	{
		if ((*stack_a)->content >= min && (*stack_a)->content < max)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	if ((*stack_a)->content >= min && (*stack_a)->content < max)
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void	split_stack(t_list **stack_a, t_list **stack_b)
{
	int				*tab;
	int				size;
	unsigned int	size_diff;

	tab = get_mid(stack_copy(stack_a));
	size = ft_lstsize(*stack_a);
	push_part(stack_a, stack_b, tab[0], tab[size / 8]);
	push_part(stack_a, stack_b, tab[size / 8], tab[size / 4]);
	push_part(stack_a, stack_b, tab[size / 4], tab[(3 * size) / 8]);
	push_part(stack_a, stack_b, tab[(3 * size) / 8], tab[size / 2]);
	push_part(stack_a, stack_b, tab[size / 2], tab[(5 * size) / 8]);
	push_part(stack_a, stack_b, tab[(5 * size) / 8], tab[(3 * size) / 4]);
	push_part(stack_a, stack_b, tab[(3 * size) / 4], tab[(7 * size) / 8]);
	size_diff = ft_lstsize(*stack_a) - ft_lstsize(*stack_b);
	while (size_diff > 1)
	{
		push_a(stack_a, stack_b);
		size_diff = ft_lstsize(*stack_a) - ft_lstsize(*stack_b);
	}
}