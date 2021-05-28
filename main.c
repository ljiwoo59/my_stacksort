#include "pushswap.h"

//test
#include <stdio.h>
void printlst(t_stack *top)
{
	t_stack *curr = top->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}
//test

int main(int argc, char *argv[])
{
	t_stack *top_a;
	t_stack *top_b;
	int i;

	if (!(top_a = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (!(top_b = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	top_a->next = NULL;
	top_b->next = NULL;
	i = 1;
	while (i < argc)
	{
		init_stack(top_a, argv[i]);
		i++;
	}
	//test
	push_swap(top_a, top_b);
	//printlst(top_a);
	//printf("%s\n", "-");
	//printlst(top_b);

	free_all(top_a, top_b);
	return (0);
}
