#include "push_swap.h"

void	sort(t_data *data)
{
	int	i;

	i = 0;
	data->mean = data->len_a / 2;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index < data->mean)
			push(data, B);
		else
		{
			rotate(data, A);
			i++;
		}
	}
	while (data->len_a > 3)
		push(data, B);
	i = -1;
	ft_printf("A	B\n");
	while (++i < data->len_a)
		ft_printf("%d : %d	%d : %d\n", data->stack_a[i].index, data->stack_a[i].value, data->stack_b[i].index, data->stack_b[i].value);
	i -= 1;
	while (++i < data->len_b)
		ft_printf("	%d : %d\n", data->stack_b[i].index, data->stack_b[i].value);
}

int	minor_value(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_a)
	{
		j = 0;
		while (j < data->len_a)
		{
			if (data->stack_a[i].value < data->stack_a[j].value)
				j++;
			else
				break ;
		}
		if (j == data->len_a)
			return (data->stack_a[i].index);
		i++;
	}
	return (data->stack_a[i].index);
}

// Modificar para que sea < 25 lineas

void	find_partner(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->len_a == 3 && !is_sorted(data))
		sort_three(data);
	ft_printf("Pareja ideal\n");
	while (i < data->len_b)
	{
		j = 0;
		while (j < data->len_a)
		{
			if (data->stack_b[i].value > data->stack_a[j].value)
			{
				j++;
				if (j == data->len_a)
				{
					data->stack_b[i].partner = minor_value(data);
					break ;
				}
			}
			else
			{
				data->stack_b[i].partner = data->stack_a[j].index;
				break ;
			}
		}
		movement_cost(data, i);
		ft_printf("%d : %d = %d\n", data->stack_b[i].value, data->stack_b[i].partner, data->stack_b[i].total_cost);
		i++;
	}
}

void	calculate_cost(t_data *data, int i, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			data->stack_b[i].total_cost = cost_a;
		else
			data->stack_b[i].total_cost = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a > cost_b)
			data->stack_b[i].total_cost = cost_b * -1;
		else
			data->stack_b[i].total_cost = cost_a * -1;
	}
	else
	{
		if (cost_a < 0)
			data->stack_b[i].total_cost = (cost_a * -1) + cost_b;
		else if (cost_b < 0)
			data->stack_b[i].total_cost = (cost_b * -1) + cost_a;
	}
}

void	movement_cost(t_data *data, int i)
{
	int	cost_a;
	int	cost_b;

	if (data->stack_b[i].partner < data->len_a - data->stack_b[i].partner)
		data->stack_b[i].cost_a = (data->len_a - data->stack_b[i].partner) * -1;
	else
		data->stack_b[i].cost_a = data->len_a - data->stack_b[i].partner;
	if (data->stack_b[i].index < data->len_b - data->stack_b[i].index)
		data->stack_b[i].cost_b = (data->len_b - data->stack_b[i].index) * -1;
	else
		data->stack_b[i].cost_b = data->len_b - data->stack_b[i].index;
	cost_a = data->stack_b[i].cost_a;
	cost_b = data->stack_b[i].cost_b;
	ft_printf("A: %d, B: %d\n", cost_a, cost_b);
}