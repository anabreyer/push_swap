#ifndef PUSH_SWAP__H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void    assign_index(t_stack *stack_a, int stack_size);
t_stack *fill_stack_values(int ac, char **av);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
long int	ft_atoi(const char *str);
void	ft_putstr(char *str);
int	nb_abs(int nb);
void stack_add_bottom(t_stack **stack, t_stack *new);


#endif