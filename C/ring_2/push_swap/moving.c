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
	}
	push(data, A);
}

void	less_movements(t_data *data)
{
	
}
