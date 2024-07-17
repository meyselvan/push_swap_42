/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:58:29 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:58:31 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;
	int		value;
	int		index;

	if (s_lstsize(*stack) < 2)
		return (0);
	node = *stack;
	next = node->next;
	value = node->data;
	index = node->index;
	node->data = next->data;
	node->index = next->index;
	next->data = value;
	next->index = index;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!swap(stack_a))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!swap(stack_b))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a) && swap(stack_b))
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}
