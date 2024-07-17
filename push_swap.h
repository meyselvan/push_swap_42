/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:01:41 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:32:50 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack_ab
{
	int				data;
	struct stack_ab	*next;
	int				index;
}	t_stack;

void	ft_arg_check(char **av, t_stack **stack_a);
void	fill_index_a(t_stack **stack_a);
int		a_is_sorted(t_stack **stack);
void	ft_free_stack(t_stack **argv);
void	free_arr(char **arr);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		swap(t_stack **stack);
int		push(t_stack **stack_1, t_stack **stack_2);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
int		get_min_index(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

t_stack	*s_lstnew(int data);
void	s_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*s_lstlast(t_stack *lst);
void	s_lstadd_back(t_stack **lst, t_stack *new);
int		s_lstsize(t_stack *lst);
void	ft_error(void);
void	sort3(t_stack **a);
int		get_dist(t_stack **stack, int index);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	ft_putendl_fd(char *s, int fd);

#endif