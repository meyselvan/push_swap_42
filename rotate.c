/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:58:12 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 01:00:58 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (s_lstsize(*stack) < 2)
		return (0);
	top = *stack;
	last = s_lstlast(*stack);
	*stack = top->next;
	top->next = NULL;
	last->next = top;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (!rotate(stack_b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
