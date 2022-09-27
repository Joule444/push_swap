/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/09/27 15:45:10 by jules            ###   ########.fr       */
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

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_error(t_list **stack_a)
{
	t_list	*elem;
	t_list	*check;

	elem = *stack_a;
	while (elem)
	{
		check = elem->next;
		while (check)
		{
			if (check->content == elem->content)
				return (1);
			check = check->next;
		}
		elem = elem->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (check_args(argv))
	{
		write(1, "Error\n", 7);
		return (0);
	}
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
	if (check_error(stack_a))
	{
		write(1, "Error\n", 7);
		return (0);
	}
	sort_stacks(stack_a, stack_b);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (free(stack_a), free(stack_b), 0);
}
