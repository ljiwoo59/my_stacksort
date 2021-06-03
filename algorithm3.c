#include "pushswap.h"

void div_a_rra(t_stack *top_a, int r, int num)
{
	if (num < stack_size(top_a))
		while ((r--) != 1)
			rra(top_a);
}

void div_a2(t_stack *top_a, int num)
{
	if (num == 2)
		if (top_a->next->data > top_a->next->next->data)
			sa(top_a);
	if (num == 3)
		size_3_sort(top_a);
}

void b_to_a2(t_stack *top_a, t_stack *top_b, t_count *curr, int num)
{
	if (num == 3)
	{
		while (num--)
			pa(top_b, top_a);
		size_3_sort(top_a);
		free_count(curr);
	}
	else if (num == 2)
	{
		while (num--)
			pa(top_b, top_a);
		if (top_a->next->data > top_a->next->next->data)
			sa(top_a);
		free_count(curr);
	}
	else if (num == 1)
	{
		pa(top_b, top_a);
		free_count(curr);
	}
}
