#include "pushswap.h"

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
