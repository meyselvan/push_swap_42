/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:56:37 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 09:27:59 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack_a;
	while (node != NULL)
	{
		temp = node->next;
		while (temp != NULL)
		{
			if (node->data == temp->data)
				ft_error();
			temp = temp->next;
		}
		node = node->next;
	}
}

void	ft_control(char **argv, long long data, int index)
{
	int	i;

	if (data < -2147483648 || data > 2147483647)
		ft_error();
	i = 0;
	if (argv[index][0] == '-')
		i++;
	if (!argv[index][i])
		ft_error();
	while (argv[index][i])
	{
		if (!ft_isdigit(argv[index][i]))
			ft_error();
		i++;
	}
}

void	ft_arg_check(char **av, t_stack **stack_a)
{
	int			i;
	int			k;
	long long	data;
	char		**str;
	t_stack		*node;

	k = 1;
	while (av[k])
	{
		i = 0;
		str = ft_split(av[k], ' ');
		while (str[i])
		{
			data = ft_atoi(str[i]);
			ft_control(str, data, i);
			node = s_lstnew(data);
			s_lstadd_back(stack_a, node);
			i++;
		}
		if (str[0] == NULL)
			ft_error();
		k++;
		free_arr(str);
	}
	ft_double(stack_a);
}
