/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:29:06 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/02 11:29:08 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A	'a'
# define B	'b'
# define SS	's'
# define RR	'r'
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "./libft/inc/libft.h"
# include <stdio.h>

typedef struct stack
{
	int	value;
	int	index;
	int	partner;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}		t_stack;

typedef struct data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
	int		counter_a;
	int		counter_b;
	int		mean;
}		t_data;

/*	MOVIMIENTOS	*/

void	move_up(t_stack *stack);
void	move_down(t_stack *stack, int len);
void	swap(t_data *data, char c);
void	push(t_data *data, char c);
void	rotate(t_data *data, char c);
void	rev_rotate(t_data *data, char c);

/*	CONTROL		*/

void	exit_error(t_data *data, int error);
void	check_argv(char	**argv, t_data *data);
void	stack_argv(char	**argv, t_data *data);
void	free_stack(t_data *data);
int		is_sorted(t_data *data);

/*	ALGORITMO	*/

void	sort_three(t_data *data);
void	sort(t_data *data);
void	minor_value(t_data *data, int x); // Revisar
void	find_partner(t_data *data); // Revisar
void	movement_cost(t_data *data, int i);
//void	moving_together(t_data *data);

/*		UTILS		*/
long	ft_atoli(const char *str);
int		ft_issign(int arg);

#endif
