/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/08/19 18:01:56 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list **stack_a, t_list **stack_b) //A SUPPRIMER
{
	t_list	*elem;
	t_list	*elemb;

	elem = *stack_a;
	elemb = *stack_b;
	printf("\nSTACK A :\n");
	while (elem)
	{
		printf("%d\n", elem->content);
		elem = elem->next;
	}
	printf("\nSTACK B :\n");
	while (elemb)
	{
		printf("%d\n", elemb->content);
		elemb = elemb->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 2)
	{
		stack_a = lst_init_parse(argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
		*stack_b = NULL;
	}
	else if (argc > 2)
	{
		stack_a = lst_init(argc, argv);
		stack_b = malloc(sizeof(t_list) * ft_lstsize(*stack_a));
		*stack_b = NULL;
	}
	else
	    return (0);
	//sort(stack_a, stack_b, ft_lstlast(*stack_a));
	//prep_fusion(stack_a);
	sort(stack_a, stack_b);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (free(stack_a), free(stack_b), 0);
}