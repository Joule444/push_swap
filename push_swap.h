/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:33:28 by jules             #+#    #+#             */
/*   Updated: 2022/06/17 16:29:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str);
char	**ft_split(char const *s, char sep);

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	**lst_init_parse(char **argv);
t_list	**lst_init(int argc, char **argv);
void	ft_lstclear(t_list **lst);
int	ft_lstsize(t_list *lst);
t_list	*lst_index(t_list **list, int index);
void	swap(t_list **stack_a);

 #endif