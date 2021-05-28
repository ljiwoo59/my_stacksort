#include "pushswap.h"

void sort1(t_stack *top_a)
{
	ra(top_a);
	sa(top_a);
	rra(top_a);
}

void sort2(t_stack *top_a)
{
	ra(top_a);
	sa(top_a);
	rra(top_a);
	sa(top_a);
}

void sort3(t_stack *top_a)
{
	sa(top_a);
	ra(top_a);
	sa(top_a);
	rra(top_a);
}

void size_3_sort(t_stack *top_a)
{
	t_stack *f;

	f = top_a->next;
	if (f->data == min(top_a) && f->next->data == max(top_a))
		sort1(top_a);
	else if (f->next->data == min(top_a) && f->next->next->data == max(top_a))
		sa(top_a);
	else if (f->next->data == max(top_a) && f->next->next->data == min(top_a))
		sort2(top_a);
	else if (f->data == max(top_a) && f->next->data == min(top_a))
		sort3(top_a);
	else if (f->data == max(top_a) && f->next->next->data == min(top_a))
	{
		sa(top_a);
		ra(top_a);
		sa(top_a);
		rra(top_a);
		sa(top_a);
	}
}

void size_3_sort2(t_stack *top_a)
{
	f = top_a->next;
	if (f->data == min(top_a) && f->next->data == max(top_a))
	{
		rra(top_a);
		sa(top_a);
	}
	else if (f->next->data == min(top_a) && f->next->next->data == max(top_a))
		sa(top_a);
	else if (f->next->data == max(top_a) && f->next->next->data == min(top_a))
		rra(top_a);
	else if (f->data == max(top_a) && f->next->data == min(top_a))
		ra(top_a);
	else if (f->data == max(top_a) && f->next->next->data == min(top_a))
	{
		ra(top_a);
		sa(top_a);
	}
}
