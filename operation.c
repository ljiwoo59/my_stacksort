/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:39:48 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 14:45:08 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *top)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (stack_size(top) > 1)
	{
		tmp = top->next;
		top->next = tmp->next;
		tmp2 = top->next->next;
		top->next->next = tmp;
		top->next->next->next = tmp2;
	}
}

void	push(t_stack *top1, t_stack *top2)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (top1->next != NULL)
	{
		tmp = top1->next;
		top1->next = top1->next->next;
		tmp2 = top2->next;
		top2->next = tmp;
		top2->next->next = tmp2;
	}
}

void	shift_up(t_stack *top)
{
	t_stack *tmp;
	t_stack *curr;

	if (stack_size(top) > 1)
	{
		tmp = top->next;
		top->next = top->next->next;
		curr = top->next;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = tmp;
		curr->next->next = NULL;
	}
}

void	shift_down(t_stack *top)
{
	t_stack *tmp;
	t_stack *curr;

	if (stack_size(top) > 1)
	{
		curr = top->next;
		while (curr->next->next != NULL)
			curr = curr->next;
		tmp = curr->next;
		tmp->next = top->next;
		top->next = tmp;
		curr->next = NULL;
	}
}
