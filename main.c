/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/10/24 16:44:04 by jthuysba         ###   ########.fr       */
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

int	check_args_space(char **argv)
{
	int		i;
	int		j;
	long	nb;

	i = 1;
	j = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		if (argv[i][j] == '-')
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

int	check_args_1(char **argv)
{
	char	**arr;
	int		i;
	int		j;
	long	nb;

	arr = ft_split(argv[1], ' ');
	i = 1;
	j = 0;
	while (arr[i])
	{
		nb = ft_atoi(arr[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		if (arr[i][j] == '-')
			j++;
		while (arr[i][j])
		{
			if (arr[i][j] < 48 || arr[i][j] > 57)
				return (free(arr), 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (free(arr), 0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
		return (check_args_1(argv));
	else
		return (check_args_space(argv));
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

	if (check_args(argc, argv))
		return (write(1, "Error\n", 7), 0);
	if (argc == 2)
	{
		stack_a = lst_init_parse(argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
	}
	else if (argc > 2)
	{
		stack_a = lst_init(argc, argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
	}
	else
		return (0);
	if (!stack_a || !stack_b)
		return (ft_lstclear(stack_a), ft_lstclear(stack_b),
			free(stack_a), free(stack_b), 0);
	if ((argc == 2 && ft_strlen(argv[1]) == 1))
		return (ft_lstclear(stack_a), ft_lstclear(stack_b),
			free(stack_a), free(stack_b), 0);
	if (check_error(stack_a))
		return (ft_lstclear(stack_a), ft_lstclear(stack_b),
			free(stack_a), free(stack_b), write(1, "Error\n", 7), 0);
	sort_stacks(stack_a, stack_b);
	return (ft_lstclear(stack_a), ft_lstclear(stack_b),
		free(stack_a), free(stack_b), 0);
}
