/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:58:52 by jules             #+#    #+#             */
/*   Updated: 2022/06/17 11:51:36 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
    t_list  **list;
    t_list  *elem;

    if (argc == 2)
        list = lst_init_parse(argv);
    else if (argc > 2)
        list = lst_init(argc, argv);
    elem = *list;
    while (elem)
    {
        ft_printf("%d\n", elem->content);
        elem = elem->next;
    }
    ft_lstclear(list);
    return (free(list), 0);
}