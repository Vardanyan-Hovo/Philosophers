/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:12 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/24 15:46:11 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_to_eat(t_data *philo_programm, t_philo_data *philo)
{
	int	right;
	int	left;

	left = philo->id;
	if (philo->id == 0)
		right = philo_programm->number_of_philosophers - 1;
	else
		right = philo->id - 1;
	while (philo_programm->if_did_anyone[0] != 1)
	{
		pthread_mutex_lock(&philo_programm->forks[left]);
		my_prints(1, philo->id, philo_programm);
		pthread_mutex_lock(&philo_programm->forks[right]);
		my_prints(2, philo->id, philo_programm);
		my_prints(3, philo->id, philo_programm);
		philo->time_eat = my_time();
		my_usleep(philo_programm->time_to_eat);
		if (philo_programm->number_of_eat)
			philo->number_eat++;
		pthread_mutex_unlock(&philo_programm->forks[left]);
		pthread_mutex_unlock(&philo_programm->forks[right]);
		my_prints(4, philo->id, philo_programm);
		my_usleep(philo_programm->time_to_sleep);
		my_prints(6, philo->id, philo_programm);
	}
}

void	mutex_init(t_data *func_live_programm)
{
	int	i;

	i = 0;
	pthread_mutex_init(&func_live_programm[0].meals, NULL);
	while (i < func_live_programm[0].number_of_philosophers)
	{
		func_live_programm[i].philo->time_eat = func_live_programm[i].time[0];
		pthread_mutex_init(&(func_live_programm[i].forks[i]), NULL);
		i++;
	}
}

void	*func_live(void *func_live_programm)
{
	t_data			*philo_struct;
	t_philo_data	*philo;

	philo_struct = (t_data *)func_live_programm;
	if (!philo_struct)
	{
		printf("\n-------ERROR------\n");
		return (NULL);
	}
	philo = philo_struct->philo;
	if (philo->id % 2)
		my_usleep(1);
	start_to_eat(philo_struct, philo);
	return (NULL);
}

void	threat(t_data *philo_programm)
{
	int	i;

	i = 0;
	if (!philo_programm)
	{
		free_all(philo_programm);
		return ;
	}
	philo_programm[0].time[0] = my_time();
	mutex_init(philo_programm);
	while (i < philo_programm[0].number_of_philosophers)
	{
		pthread_create(&(philo_programm[i].thread), NULL,
			func_live, (void *)(&philo_programm[i]));
		pthread_detach(philo_programm[i].thread);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		number_of_philosophers;
	int		i;
	t_data	*philo_programm;

	i = 0;
	if (argc >= 5 && argc <= 6)
	{
		if (shearch_error(argv))
			return (0);
		number_of_philosophers = ft_atoi(argv[1]);
		philo_programm = initial_value(argc, argv, number_of_philosophers, -1);
		if (!philo_programm)
		{
			printf("ERROR:\n");
			return (-1);
		}
		threat(philo_programm);
		if (if_any_one_die(philo_programm, -1))
			return (0);
	}
	else
		write (2, "Incorrect input\n", 16);
	return (0);
}
