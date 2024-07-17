/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:57:54 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:57:55 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack **stack)
{
	t_stack	*node;
	int		max_index;
	int		max_bit;

	node = *stack;
	max_index = node->index;
	max_bit = 0;
	while (node != NULL)
	{
		if (node->index > max_index)
			max_index = node->index;
		node = node->next;
	}
	while (max_index >> max_bit)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = s_lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if ((head_a->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (s_lstsize(*b))
			pa(a, b);
		i++;
	}
}
