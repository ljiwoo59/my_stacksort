#include "pushswap.h"

void div_a(t_stack *top_a, t_stack *top_b, t_count *here, int num)
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
			if (top_a->next->data <= pivot)
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
	if (num == 2)
		if (top_a->next->data > top_a->next->next->data)
			sa(top_a);
	if (num == 3)
		size_3_sort(top_a);
	b_to_a(top_a, top_b, here);
}

void div_b(t_stack *top_b, t_stack *top_a, t_count *curr, int num)
{
	int pivot;
	int i;
	int r;
	int c;

	pivot = find_pivot(top_b, num);
	i = 0;
	r = 0;
	c = 0;
	while (num - c)
	{
		if (top_b->next->data > pivot)
		{
			pa(top_b, top_a);
			i++;
		}
		else
		{
			rb(top_b);
			r++;
		}
		c++;
	}
	if (num < stack_size(top_b))
		while (r--)
			rrb(top_b);
	curr->next->count -= i;
	div_a(top_a, top_b, curr, i);
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
		if (num > 3)
			div_b(top_b, top_a, curr, num);
		else if (num == 3)
		{
			while (num--)
				pa(top_b, top_a);
			size_3_sort(top_a);
			free(curr->next);
			curr->next = NULL;
		}
		else if (num == 2)
		{
			while (num--)
				pa(top_b, top_a);
			if (top_a->next->data > top_a->next->next->data)
				sa(top_a);
			free(curr->next);
			curr->next = NULL;
		}
		else if (num == 1)
		{
			pa(top_b, top_a);
			free(curr->next);
			curr->next = NULL;
		}
	}
}
