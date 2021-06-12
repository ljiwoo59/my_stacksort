/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:37:15 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 14:55:26 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	div_a5(t_stack *top_a, t_stack *top_b, t_count *here, int num)
{
	int pivot;
	int i;
	int c;

	pivot = find_pivot(top_a, num);
	i = 0;
	c = 1;
	while (num - (i++))
	{
		if (top_a->next->data < pivot && c++)
			pb(top_a, top_b);
		else
			ra(top_a);
	}
	count_append(here, c - 1);
	num -= (c - 1);
	size_3_sort2(top_a);
	b_to_a(top_a, top_b, here);
}

void	div_a(t_stack *top_a, t_stack *top_b, t_count *here, int num)
{
	int pivot;
	int i;
	int c;
	int r;

	while (num > 3)
	{
		pivot = find_pivot(top_a, num);
		i = 0;
		c = 1;
		r = 1;
		while (num - (i++))
		{
			if (top_a->next->data <= pivot && c++)
				pb(top_a, top_b);
			else if (r++)
				ra(top_a);
		}
		div_a_rra(top_a, r, num);
		count_append(here, c - 1);
		num -= (c - 1);
	}
	div_a2(top_a, num);
	b_to_a(top_a, top_b, here);
}

void	div_b(t_stack *top_b, t_stack *top_a, t_count *curr, int num)
{
	int	pivot;
	int	i;
	int	r;
	int	c;

	pivot = find_pivot(top_b, num);
	i = 1;
	r = 1;
	c = 0;
	while (num - (c++))
	{
		if (top_b->next->data > pivot && i++)
			pa(top_b, top_a);
		else if (r++)
			rb(top_b);
	}
	if (num < stack_size(top_b))
		while ((r--) != 1)
			rrb(top_b);
	curr->next->count -= (i - 1);
	div_a(top_a, top_b, curr, i - 1);
}

void	b_to_a(t_stack *top_a, t_stack *top_b, t_count *here)
{
	t_count	*curr;
	int		num;

	while (count_size(here))
	{
		curr = here;
		while (curr->next->next != NULL)
			curr = curr->next;
		num = curr->next->count;
		if (num > 3)
			div_b(top_b, top_a, curr, num);
		b_to_a2(top_a, top_b, curr, num);
	}
}
