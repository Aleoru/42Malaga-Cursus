#include "push_swap.h"

void	rotate(t_data *data, char c)
{
	t_stack aux;

	if (c == A || c == RR)
	{
		aux = data->stack_a[0];
		move_up(data->stack_a, data->len_a);
		data->stack_a[data->len_a] = aux;
		ft_printf("ra");
		if (c = A)
			ft_printf("ra\n");
	}
	if (c == B || c == RR)
	{
		aux = data->stack_a[0];
		move_up(data->stack_a, data->len_a);
		data->stack_a[data->len_a] = aux;
		if (c = B)
			ft_printf("rb\n");
	}
	if (c == RR)
		ft_printf("rr\n")
}