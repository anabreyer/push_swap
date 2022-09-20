#include "push_swap.h"

static void get_position(t_stack **stack)
{
    t_stack *tmp;
    int i;

    tmp = *stack;
    i = 0;
    while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int get_target(t_stack **a, int b_index, int target_index, int target_position)
{
    t_stack *tmp_a;

    	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_position = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_position);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_position = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_position);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}