/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:58:16 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 09:25:03 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_dist(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min_index(t_stack **stack)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min)
			min = head->index;
	}
	return (min);
}

void	sort3(t_stack **a)
{
	if (a_is_sorted(a))
		return ;
	if ((*a)->index == get_min_index(a)
		&& (*a)->next->index != get_min_index(a) + 1)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if ((*a)->index == get_min_index(a) + 1
		&& (*a)->next->index == get_min_index(a))
		sa(a);
	else if ((*a)->index == get_min_index(a) + 1
		&& (*a)->next->index != get_min_index(a))
		rra(a);
	else
	{
		if ((*a)->next->index == get_min_index(a))
			ra(a);
		else
		{
			ra(a);
			sa(a);
		}
	}
}
