/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:56:46 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 03:55:49 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min_node;
	int		ctrl;

	head = *stack;
	min_node = NULL;
	if (head == NULL)
		return (NULL);
	while (head != NULL)
	{
		if (head->index == -1)
		{
			if (!min_node || head->data < min_node->data)
				min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

void	fill_index_a(t_stack **stack_a)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = next_min(stack_a);
	while (head != NULL)
	{
		head->index = index++;
		head = next_min(stack_a);
	}
}
