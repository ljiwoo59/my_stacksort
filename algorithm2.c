#include "pushswap.h"

int div_a(t_stack *top_a, t_stack *top_b, t_count *here, int num)
{
	int pivot;
	int i;
	int c;
	int r;

	while (num > 3)
	{
		pivot = find_pivot(top_a, num);
		i = 0;
		c = 0;
		r = 0;
		while (num - i)
		{
			if (top_a->next->data < pivot)
			{
				pb(top_a, top_b);
				c++;
			}
			else
			{
				ra(top_a);
				r++;
			}
			i++;
		}
		if (num < stack_size(top_a))
		{
			while (r--)
				rra(top_a);
		}
		count_append(here, c);
		num -= c;
	}
	return (num);
}

void b_to_a(t_stack *top_a, t_stack *top_b, t_count *here)
{
	t_count *curr;
	int num;

	while (count_size(here))
	{
		curr = here;
		while (curr->next->next != NULL)
			curr = curr->next;
		num = curr->next->count;
		while ((curr->next->count)--)
			pa(top_b, top_a);
		free(curr->next);
		curr->next = NULL;
		if (num > 3)
			num = div_a(top_a, top_b, here, num);
		if (num == 2)
			if (top_a->next->data > top_a->next->next->data)
				sa(top_a);
		if (num == 3)
			size_3_sort(top_a);
	}
}
