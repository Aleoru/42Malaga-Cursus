#include "push_swap.h"

void	sort(t_data *data)
{
	int	i;

	i = 0;
	data->mean = data->len_a / 2;
	while (i < data->len_a && data->len_a > 3)
	{
		if (data->stack_a[0].index < data->mean)
			push(data, B);
		else
		{
			rotate(data, A);
			i++;
		}
	}
	while (data->len_a > 3)
		push(data, B);
	if (!is_sorted(data))
		sort_three(data);
	ft_printf("----------------------------\n");
	i = -1;
	ft_printf("A	B\n");
	while (++i < data->len_a)
		ft_printf("%d : %d	%d : %d\n", data->stack_a[i].index, data->stack_a[i].value, data->stack_b[i].index, data->stack_b[i].value);
	i -= 1;
	while (++i < data->len_b)
		ft_printf("	%d : %d\n", data->stack_b[i].index, data->stack_b[i].value);
}

void	minor_value(t_data *data, int x)
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
		{
			data->stack_b[x].partner = data->stack_a[i].index;
			return ;
		}
		i++;
	}
}

static int is_mayor(t_data *data, int index)
{
	int		i;

	i = 0;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index > index)
			return (0);
		i++;
	}
	return (1);
}

static int	mayor_a(t_data *data)
{
	int	mayor;
	int	i;

	i = 0;
	mayor = data->stack_a[0].index;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index > mayor)
			mayor = data->stack_a[i].index;
		i++;
	}
	return (mayor);
}

void find_partner(t_data *data)
{
	int		i;
	int		j;
	int		mayor;

	i = 0;
	while (i < data->len_b)
	{
		if (is_mayor(data, data->stack_b[i].index))
			minor_value(data, i);
		else
		{
			mayor = mayor_a(data);
			j = 0;
			while (j < data->len_a)
			{
				if (data->stack_a[j].index < mayor 
					&& data->stack_b[i].index < data->stack_a[j].index)
					mayor = data->stack_a[j].index;
				j++;
			}
			data->stack_b[i].partner = mayor;
		}
		printf("Pareja: %d:%d\n", data->stack_b[i].index, data->stack_b[i].partner);
		movement_cost(data, i);
		i++;
	}
}

void	calculate_cost(t_data *data, int i, int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			data->stack_b[i].total_cost = cost_a;
		else
			data->stack_b[i].total_cost = cost_b;
	}
	else if (cost_a <= 0 && cost_b <= 0)
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

static int pos_index(t_data *data, char array ,int index)
{
	int 	pos;

	pos = 0;
	if (array == 'a')
	{
		while (pos < data->len_a)
		{
			if (data->stack_a[pos].index == index)
				return (pos);
			pos++;
		}
	}
	else
		while (pos < data->len_b)
		{
			if (data->stack_b[pos].index == index)
				return (pos);
			pos++;
		}
	return (-1);
}

void	movement_cost(t_data *data, int i)
{
	int	cost_a;
	int	cost_b;
	data->stack_b[i].pos_a = pos_index(data, 'a', data->stack_b[i].partner);
	data->stack_b[i].pos_b = pos_index(data, 'b', data->stack_b[i].index);
	if (data->stack_b[i].pos_a > data->len_a - data->stack_b[i].pos_a)
		data->stack_b[i].cost_a = (data->len_a - data->stack_b[i].pos_a) * -1;
	else
		data->stack_b[i].cost_a = data->stack_b[i].pos_a;
	if (data->stack_b[i].pos_b > data->len_b - data->stack_b[i].pos_b)
		data->stack_b[i].cost_b = (data->len_b - data->stack_b[i].pos_b) * -1;
	else
		data->stack_b[i].cost_b = data->stack_b[i].pos_b;
	cost_a = data->stack_b[i].cost_a;
	cost_b = data->stack_b[i].cost_b;
	calculate_cost(data, i, cost_a, cost_b);
	ft_printf("Nº: %d, A: %d, B: %d = %d\n", data->stack_b[i].value, data->stack_b[i].cost_a, data->stack_b[i].cost_b, data->stack_b[i].total_cost);
}

void	final_rotation(t_data *data)
{
	int	i;

	i = 0;
	while (data->stack_a[i].index != 0)
		i++;
	if (i > data->mean)
		rev_rotate(data, A);
	else if (i < data->mean)
		rotate(data, A);
	if (data->stack_a[0].index != 0)
		final_rotation(data);
}
