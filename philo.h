/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:39:05 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/24 15:50:17 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct philo
{
	int				id;
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	int				number_eat;
	long long int	x;
	long long int	y;
}					t_philo_data;

typedef struct philo_x
{
	int				id;
	long long int	*time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	prints;
	pthread_mutex_t	meals;
	int				*if_did_anyone;
	int				number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_eat;
	pthread_t		thread;
	t_philo_data	*philo;
}					t_data;

void		my_prints(int evnt, int id, t_data *data);
int			if_all_are_eaten(t_data *philo_programm);
int			ft_atoi(const char *str);
void		func_philo_print(t_data *programm);
int			if_any_one_die(t_data *philo_programm, int i);
void		my_usleep(long long x);
void		func_philo_print_philosophers(t_data *programm);
t_data		*initial_value(int count, char **argv,
				int number_of_philosophers, int i);
long long	my_time(void);
void		mutex_detech(t_data *func_live_programm);
int			shearch_error(char **argv);
void		start_to_eat(t_data *philo_programm,
				t_philo_data *philo);
void		free_all(t_data *philo_programm);

#endif
