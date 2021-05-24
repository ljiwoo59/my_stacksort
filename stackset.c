#include "pushswap.h"

void init_stack(t_stack *top, char *data)
{
	t_stack *new;
	t_stack *curr;
	t_stack *tmp;
	int num;
	
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	new->next = NULL;
	num = ft_atoi(data);
	if (top->next == NULL)
	{
		top->next = new;
		new->data = num;
	}
	else
	{
		curr = top->next;
		while (curr != NULL)
		{
			tmp = curr;
			if (curr->data == num)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			curr = curr->next;
		}
		new->data = num;
		tmp->next = new;
	}
}

int is_sorted(t_stack *top_a, t_stack *top_b)
{
	t_stack *curr;
	int tmp;

	if (stack_size(top_b) != 0)
		return (0);
	curr = top_a->next;
	tmp = curr->data;
	while (curr != NULL)
	{
		if (tmp > curr->data)
			return (0);
		tmp = curr->data;
		curr = curr->next;
	}
	return (1);
}
