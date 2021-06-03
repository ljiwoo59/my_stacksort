#include "pushswap.h"

void sa(t_stack *top_a)
{
	swap(top_a);
	write(1, "sa\n", 3);
}

void sb(t_stack *top_b)
{
	swap(top_b);
	write(1, "sb\n", 3);
}

void ss(t_stack *top_a, t_stack *top_b)
{
	swap(top_a);
	swap(top_b);
	write(1, "ss\n", 3);
}

void pa(t_stack *top_b, t_stack *top_a)
{
	push(top_b, top_a);
	write(1, "pa\n", 3);
}

void pb(t_stack *top_a, t_stack *top_b)
{
	push(top_a, top_b);
	write(1, "pb\n", 3);
}
