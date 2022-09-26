/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/09/26 12:52:27 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a))
		return ;
	else if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 2)
	{
		stack_a = lst_init_parse(argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
		if (!stack_b)
			return (0);
		*stack_b = NULL;
	}
	else if (argc > 2)
	{
		stack_a = lst_init(argc, argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
		if (!stack_b)
			return (0);
		*stack_b = NULL;
	}
	else
		return (0);
	sort_stacks(stack_a, stack_b);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (free(stack_a), free(stack_b), 0);
}
