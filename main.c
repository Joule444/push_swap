/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/10/25 16:13:47 by jthuysba         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	**get_stack(int argc, char **argv)
{
	t_list	**stack_a;

	if (argc == 2)
		stack_a = lst_init_parse(argv);
	else
		stack_a = lst_init(argc, argv);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (check_args(argc, argv))
		return (write(1, "Error\n", 7), 0);
	if (argc <= 1)
		return (0);
	stack_a = get_stack(argc, argv);
	stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
	if (!stack_a || !stack_b)
		return (ft_lstclear(stack_a), ft_lstclear(stack_b),
			free(stack_a), free(stack_b), 0);
	if (argc == 2 && check_sorted(stack_a))
		return (ft_lstclear(stack_a),
			free(stack_a), free(stack_b), 0);
	if (check_error(stack_a))
		return (ft_lstclear(stack_a),
			free(stack_a), free(stack_b), write(1, "Error\n", 7), 0);
	sort_stacks(stack_a, stack_b);
	return (ft_lstclear(stack_a), ft_lstclear(stack_b),
		free(stack_a), free(stack_b), 0);
}
