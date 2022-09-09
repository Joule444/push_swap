/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:33:28 by jules             #+#    #+#             */
/*   Updated: 2022/09/09 13:17:00 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *str);
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
int		ft_lstsize(t_list *lst);
t_list	*lst_index(t_list **list, int index);
t_list	*lst_previous(t_list **stack, t_list *aim);

//INSTRUCTIONS
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

void	grab_a(t_list *aim, t_list **stack_a);
void	sort(t_list **stack_a, t_list **stack_b);
void	prep_fusion(t_list **stack_a);
void	bubble_sort(t_list **stack_a, t_list **stack_b, t_list *end_a, t_list *end_b);
void	split_stack(t_list **stack_a, t_list **stack_b);
int	check_sorted(t_list **stack, t_list *start, t_list *end);
int	check_sorted_rev(t_list **stack, t_list *start, t_list *end);

 #endif