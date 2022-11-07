/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:50:10 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/07 15:33:27 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (argv[i][j] == '-' &&
			(argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57))
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

int	check_string(char *str, int start)
{
	while (str[start])
	{
		if (str[start] < 48 || str[start] > 57)
			return (1);
		start++;
	}
	return (0);
}

int	check_args_1(char **argv)
{
	char	**arr;
	int		i;
	long	nb;
	int		j;

	arr = ft_split(argv[1], ' ');
	i = 0;
	j = 0;
	while (arr[i])
	{
		nb = ft_atoi(arr[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (free_arr(arr), 1);
		if (arr[i][0] == '-' &&
				((arr[i][1] >= 48 && arr[i][1] <= 57)))
				j++;
		if (check_string(arr[i], j))
			return (free_arr(arr), 1);
		i++;
		j = 0;
	}
	return (free_arr(arr), 0);
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
