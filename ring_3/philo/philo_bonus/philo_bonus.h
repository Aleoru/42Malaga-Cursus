/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:13:14 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:15 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define DEAD	0
# define SLEEP	1
# define THINK	2
# define HUNGRY	3
# define EATING	4
# define EXIT_FULL 0
# define EXIT_DEAD 1

typedef struct s_philo
{
	pthread_t	th_philo;
	time_t		t_next_state;
	time_t		t_die;
	pid_t		pid;
	int			name;
	int			meals;
	int			state;
	int			picked;
}		t_philo;

typedef struct s_table
{
	t_philo			philo;
	time_t			start;
	pid_t			*pid;
	sem_t			*sem_fork;
	sem_t			*sem_write;
	int				num_philo;
	int				fork_pairs;
	int				pos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				f_meals;
	int				one_fork;
	int				end;
}		t_table;

/*
*	PROGRAM
*/

void	*routine(void *data);
void	check_state(t_table *table);
void	eating(t_table *table);
void	print_state(t_table *table);
void	release_forks(t_table *table);

/*
*	CONTROL
*/

int		check_argv(char **argv);
int		check_table(t_table *table, int argc);
int		exit_error(int error);
void	close_processes(t_table *table);
void	close_sem(t_table *table);

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
