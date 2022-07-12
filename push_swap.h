/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:33:28 by jules             #+#    #+#             */
/*   Updated: 2022/07/12 18:14:05 by jules            ###   ########.fr       */
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
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	**lst_init_parse(char **argv);
t_list	**lst_init(int argc, char **argv);
void	ft_lstclear(t_list **lst);
int	ft_lstsize(t_list *lst);
t_list	*lst_index(t_list **list, int index);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_s(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_r(t_list **stack_a, t_list **stack_b);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_r(t_list **stack_a, t_list **stack_b);
void	trade(t_list *a, t_list *b, t_list **stack_a, t_list **stack_b);
void	grab_a(t_list *aim, t_list **stack_a);
void	sort(t_list **stack_a, t_list **stack_b, t_list *start, t_list *pivot);
int	check_sorted(t_list **stack, t_list *start, t_list *end);

 #endif