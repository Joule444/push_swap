/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:22:11 by jules             #+#    #+#             */
/*   Updated: 2022/07/04 15:53:06 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	a->content = content;
	a->next = NULL;
	return (a);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (lst)
	{
		if (*lst)
		{
			a = ft_lstlast(*lst);
			a->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*elem;

	if (lst)
	{
		while (*lst)
		{
			elem = (*lst)->next;
			free(*lst);
			*lst = elem;
		}
	}
}

int	ft_lstsize(t_list *lst)
{
	int	a;

	a = 0;
	if (lst)
	{
		while (lst)
		{
			a++;
			lst = lst->next;
		}
	}
	return (a);
}
