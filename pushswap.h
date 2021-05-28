#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

void printlst(t_stack *top);

int ft_atoi(char *str);
int validation(char *str);
int stack_size(t_stack *top);
int count_size(t_count *here);
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
void stack_append(t_stack *top, t_stack *new, int num);
void push_swap(t_stack *top_a, t_stack *top_b);
void count_append(t_count *curr, int c);
void size_3_sort(t_stack *top_a);
void size_3_sort2(t_stack *top_a);
void sort1(t_stack *top_a);
void sort2(t_stack *top_a);
void sort3(t_stack *top_a);
int max(t_stack *top);
int min(t_stack *top);
void init_push(t_stack *top_a, t_stack *top_b);
int find_pivot(t_stack *top, int num);
void bubble_sort(int *arr, int n);
void index_swap(int *i, int *j);
void div_a(t_stack *top_a, t_stack *top_b, t_count *here, int num);
void div_a5(t_stack *top_a, t_stack *top_b, t_count *here, int num);
void div_b(t_stack *top_b, t_stack *top_a, t_count *here, int num);
void b_to_a(t_stack *top_a, t_stack *top_b, t_count *here);
void free_all(t_stack *top_a, t_stack *top_b);

int ft_strcmp(char *s1, char *s2);
int is_sorted(t_stack *top_a, t_stack *top_b);
#endif
