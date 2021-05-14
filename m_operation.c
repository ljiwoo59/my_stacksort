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

void ra(t_stack *top_a)
{
	shift_up(top_a);
	write(1, "ra\n", 3);
}

void rb(t_stack *top_b)
{
	shift_up(top_b);
	write(1, "rb\n", 3);
}

void rr(t_stack *top_a, t_stack *top_b)
{
	shift_up(top_a);
	shift_up(top_b);
	write(1, "rr\n", 3);
}

void rra(t_stack *top_a)
{
	shift_down(top_a);
	write(1, "rra\n", 4);
}

void rrb(t_stack *top_b)
{
	shift_down(top_b);
	write(1, "rrb\n", 4);
}

void rrr(t_stack *top_a, t_stack *top_b)
{
	shift_down(top_a);
	shift_down(top_b);
	write(1, "rrr\n", 4);
}
