/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-lee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:39:59 by ji-lee            #+#    #+#             */
/*   Updated: 2021/06/12 14:51:18 by ji-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		find_pivot(t_stack *top, int num)
{
	int		tmp_arr[num];
	t_stack	*curr;
	int		i;

	curr = top->next;
	i = 0;
	while (i < num)
	{
		tmp_arr[i++] = curr->data;
		curr = curr->next;
	}
	bubble_sort(tmp_arr, num);
	if (num % 2 == 0)
		return (tmp_arr[(num / 2) - 1]);
	else
		return (tmp_arr[(num / 2)]);
}

void	push_swap(t_stack *top_a, t_stack *top_b)
{
	t_count *here;

	if (!(here = (t_count *)malloc(sizeof(t_count))))
		error();
	here->next = NULL;
	if (stack_size(top_a) == 3)
		size_3_sort2(top_a);
	else if (stack_size(top_a) == 5)
		div_a5(top_a, top_b, here, stack_size(top_a));
	else
		div_a(top_a, top_b, here, stack_size(top_a));
	free(here);
}
