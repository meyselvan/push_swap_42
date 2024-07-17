/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:58:20 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:58:22 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort4(t_stack **a, t_stack **b)
{
	int	d;
	int	min;

	min = get_min_index(a);
	if (a_is_sorted(a))
		return ;
	d = get_dist(a, min);
	if (d == 1)
		sa(a);
	else if (d == 2)
	{
		ra(a);
		ra(a);
	}
	else if (d == 3)
		rra(a);
	if (a_is_sorted(a))
		return ;
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{
	int	d;

	d = get_dist(a, get_min_index(a));
	if (d == 1)
		sa(a);
	else if (d == 2)
	{
		ra(a);
		ra(a);
	}
	else if (d == 3)
	{
		rra(a);
		rra(a);
	}
	else if (d == 4)
		rra(a);
	if (a_is_sorted(a))
		return ;
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}
