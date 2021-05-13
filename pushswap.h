#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack *next;
	int data;
}	t_stack;

int ft_atoi(char *str);
int validation(char *str);
int stack_size(t_stack *top);
void swap(t_stack *top);
void push(t_stack *top1, t_stack *top2);
void shift_up(t_stack *top);
void shift_down(t_stack *top);
void init_stack(t_stack *top, char *data);
void printlst(t_stack *top);

#endif
