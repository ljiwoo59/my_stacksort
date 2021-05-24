#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack *next;
	int data;
}	t_stack;

typedef struct s_count
{
	struct s_count *next;
	int count;
}	t_count;

int ft_atoi(char *str);
int validation(char *str);
int stack_size(t_stack *top);
void swap(t_stack *top);
void push(t_stack *top1, t_stack *top2);
void shift_up(t_stack *top);
void shift_down(t_stack *top);
void sa(t_stack *top_a);
void sb(t_stack *top_b);
void ss(t_stack *top_a, t_stack *top_b);
void pa(t_stack *top_b, t_stack *top_a);
void pb(t_stack *top_a, t_stack *top_b);
void ra(t_stack *top_a);
void rb(t_stack *top_b);
void rr(t_stack *top_a, t_stack *top_b);
void rra(t_stack *top_a);
void rrb(t_stack *top_b);
void rrr(t_stack *top_a, t_stack *top_b);
void init_stack(t_stack *top, char *data);
void printlst(t_stack *top);


int ft_strcmp(char *s1, char *s2);
int is_sorted(t_stack *top_a, t_stack *top_b);
#endif
