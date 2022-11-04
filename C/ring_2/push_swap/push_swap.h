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

# include "./libft/inc/libft.h"

typedef struct stack
{
	int	value;
	int	index;
}		t_stack;

typedef struct data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
	int		mean;
}		t_data;

/*	MOVIMIENTOS	*/

void	move_up(t_stack *stack);
void	move_down(t_stack *stack, int len);
void	swap(t_data *data, char c);
void	push(t_data *data, char c);
void	rotate(t_data *data, char c);
void	rev_rotate(t_data *data, char c);

#endif
