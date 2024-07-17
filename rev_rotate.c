/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:57:59 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:58:00 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (s_lstsize(*stack) < 2)
		return (0);
	top = *stack;
	last = s_lstlast(*stack);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == 0)
		return (0);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == 0)
		return (0);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((s_lstsize(*stack_a) < 2) || (s_lstsize(*stack_b) < 2))
		return (0);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (1);
}
