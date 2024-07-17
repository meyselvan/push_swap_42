/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:57:47 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:57:48 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (s_lstsize(*stack_2) == 0)
		return (0);
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (!*stack_1)
	{
		tmp->next = NULL;
		*stack_1 = tmp;
	}
	else
	{
		tmp->next = *stack_1;
		*stack_1 = tmp;
	}
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_a, stack_b))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_b, stack_a))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}
