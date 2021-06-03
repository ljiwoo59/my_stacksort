#include "pushswap.h"

void rrr(t_stack *top_a, t_stack *top_b)
{
	shift_down(top_a);
	shift_down(top_b);
	write(1, "rrr\n", 4);
}
