/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:58:25 by relvan            #+#    #+#             */
/*   Updated: 2024/01/12 00:58:27 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*s_lstnew(int data)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	s_lstsize(t_stack *lst)
{
	int		len;
	t_stack	*p;

	p = lst;
	len = 0;
	while (p)
	{
		p = p -> next;
		len++;
	}
	return (len);
}

void	s_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

void	s_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (*lst)
	{
		node = s_lstlast(*lst);
		node->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

t_stack	*s_lstlast(t_stack *lst)
{
	t_stack	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node -> next)
		node = node->next;
	return (node);
}
