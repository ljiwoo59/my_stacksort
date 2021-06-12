/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:39:53 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 14:57:23 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_sorted(t_stack *top_a, t_stack *top_b)
{
	t_stack	*curr;
	int		tmp;

	if (stack_size(top_b) != 0)
		return (0);
	curr = top_a->next;
	tmp = curr->data;
	while (curr != NULL)
	{
		if (tmp > curr->data)
			return (0);
		tmp = curr->data;
		curr = curr->next;
	}
	return (1);
}

void	stack_append(t_stack *top, t_stack *new, int num)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (top->next == NULL)
	{
		top->next = new;
		new->data = num;
	}
	else
	{
		curr = top->next;
		while (curr != NULL)
		{
			tmp = curr;
			if (curr->data == num)
				error();
			curr = curr->next;
		}
		new->data = num;
		tmp->next = new;
	}
}

void	count_append(t_count *curr, int c)
{
	t_count *new;

	if (!(new = (t_count *)malloc(sizeof(t_count))))
		error();
	new->next = NULL;
	new->count = c;
	if (curr->next == NULL)
		curr->next = new;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}

void	free_all(t_stack *top_a, t_stack *top_b)
{
	t_stack *curr;
	t_stack *tmp;

	curr = top_a;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	curr = top_b;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

void	free_count(t_count *curr)
{
	free(curr->next);
	curr->next = NULL;
}
