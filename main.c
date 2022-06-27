/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/06/27 11:45:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
    t_list  **stack_a;
    t_list  **stack_b;
    t_list  *elem;
    t_list  *elemb;

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
    swap(stack_a);
    elem = *stack_a;
    elemb = *stack_b;
    while (elem)
    {
        ft_printf("%d\n", elem->content);
        elem = elem->next;
    }
    while (elemb)
    {
        ft_printf("%d\n", elemb->content);
        elemb = elemb->next;
    }
    //ft_printf("%d\n", lst_index(stack_a, 0)->content);
    ft_lstclear(stack_a);
    ft_lstclear(stack_b);
    return (free(stack_a), free(stack_b), 0);
}