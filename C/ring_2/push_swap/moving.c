#include "push_swap.h"

void	moving_alone(t_data *data)
{
	while (data->counter_a > 0)
	{
		rotate(data, A);
		data->counter_a--;
	}
	while (data->counter_a < 0)
	{
		rev_rotate(data, A);
		data->counter_a++;
	}
	while (data->counter_b > 0)
	{
		rotate(data, A);
		data->counter_b--;
	}
	while (data->counter_b < 0)
	{
		rev_rotate(data, A);
		data->counter_b++;
	}
}

void	moving_together(t_data *data)
{
	while (data->counter_a != 0 || data->counter_b != 0)
	{
		while (data->counter_a > 0 && data->counter_b > 0)
		{
			rotate(data, RR);
			data->counter_a--;
			data->counter_b--;
		}
		while (data->counter_a < 0 && data->counter_b < 0)
		{
			rev_rotate(data, RR);
			data->counter_a++;
			data->counter_b++;
		}
		moving_alone(data);
	}
	push(data, A);
}

void	less_movements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_b)
	{
		j = 0;
		while (j < data->len_b)
		{
			if (data->stack_b[i].total_cost < data->stack_b[j].total_cost)
				j++;
			else
				break ;
		}
		if (j == data->len_b)
		{
			data->counter_a = data->stack_b[i].cost_a;
			data->counter_b = data->stack_b[i].cost_b;
			return ;
		}
		i++;
	}
}

void	final_sort(t_data *data)
{
		less_movements(data);
		moving_together(data);
}
