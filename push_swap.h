/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:33:28 by jules             #+#    #+#             */
/*   Updated: 2022/09/27 15:22:47 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

void	sort(t_list **stack_a, t_list **stack_b);
int		*get_tab(t_list **stack);
t_list	**stack_copy(t_list **stack);
int		better_rotate(t_list **stack, t_list *aim);
int		better_rotate_portion(t_list **stack, int max);
void	grab_elem_a(t_list *elem, t_list **stack_a);
void	grab_elem_b(t_list *elem, t_list **stack_b);
void	push_part(t_list **stack_a, t_list **stack_b, int min, int max);
void	chunk_sort(t_list **stack_a, t_list **stack_b);
int		check_sorted(t_list **stack);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		is_stack_min(t_list *elem, t_list **stack);
int		is_stack_max(t_list *elem, t_list **stack);
void	find_spot(t_list **stack_a, t_list **stack_b);

#endif