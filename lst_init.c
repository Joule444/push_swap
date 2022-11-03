/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:43:18 by jules             #+#    #+#             */
/*   Updated: 2022/11/03 18:15:46 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_list	**lst_init_parse(char **argv)
{
	t_list	**list;
	char	**arr;
	t_list	*elem;
	int		i;

	i = 0;
	arr = ft_split(argv[1], ' ');
	list = malloc(sizeof(t_list) * (arr_len(arr) - 1));
	if (!list)
		return (free(arr), NULL);
	*list = NULL;
	while (arr[i])
	{
		elem = ft_lstnew(ft_atoi(arr[i]));
		ft_lstadd_back(list, elem);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	return (free(arr), list);
}

t_list	**lst_init(int argc, char **argv)
{
	t_list	**list;
	t_list	*elem;
	int		n;
	int		i;

	list = malloc(sizeof(t_list) * (argc - 1));
	if (!list)
		return (NULL);
	*list = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		elem = ft_lstnew(n);
		ft_lstadd_back(list, elem);
		i++;
	}
	return (list);
}
