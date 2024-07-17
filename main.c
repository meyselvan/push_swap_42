/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:01:32 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 04:00:22 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	sort_func(t_stack **a, t_stack **b)
{
	int		size;

	size = s_lstsize(*a);
	if (size == 0 || size == 1)
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_error();
	}
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else if (size > 5)
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		exit (1);
	stack_a = malloc(sizeof(t_stack *));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
		ft_error();
	*stack_a = NULL;
	*stack_b = NULL;
	ft_arg_check(argv, stack_a);
	fill_index_a(stack_a);
	if (a_is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	sort_func(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
