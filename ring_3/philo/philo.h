/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:13:14 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:15 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define DEAD	0
# define SLEEP	1
# define THINK	2
# define HUNGRY	3
# define EATING	4
# define LEFT_H		'l'
# define RIGHT_H	'r'

typedef struct s_fork
{
	pthread_mutex_t	m_fork;
	int				pos;
	int				free;
}		t_fork;

typedef struct s_philo
{
	pthread_t	th_philo;
	time_t		t_next_state;
	time_t		t_die;
	int			name;
	int			fork_l;
	int			fork_r;
	int			meals;
	int			state;
	int			picked;
}		t_philo;

typedef struct s_table
{
	pthread_mutex_t	m_philo;
	pthread_mutex_t	m_write;
	t_philo			*philo;
	t_fork			*forks;
	time_t			start;
	int				num_philo;
	int				pos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				f_meals;
	int				end;
}		t_table;

/*
*	PROGRAM
*/

void	call_philos(t_table *table);
void	*routine(void *data);
void	print_state(t_table *table, int pos);
//void	eating(t_table *table, int pos);
void	clear_the_table(t_table *table);

/*
*	CONTROL
*/

int		check_argv(t_table *table, char **argv);
int		check_table(t_table *table, int argc);
int		check_meals(t_table *table);
int		check_deaths(t_table *table);
int		exit_error(t_table *table, int error);

/*
*	TIME
*/

time_t	get_time_in_ms(void);
time_t	time_from_start(t_table *table);

/*
*	UTILS
*/

int		ft_isdigit(int arg);
long	ft_atoli(const char *str);

#endif
