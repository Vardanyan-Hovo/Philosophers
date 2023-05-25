/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:59:04 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/24 15:49:05 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	func_philo_print(t_data *programm)
{
	int	i;

	i = 0;
	while (i < programm[0].number_of_philosophers)
	{
		printf("/////////////////////programm[i].time[0]== [%lld] \n",
			programm[i].time[0]);
		printf("programm[i].number_of_philosophers == %d \n",
			programm[i].number_of_philosophers);
		printf("programm[i].id ==                     %d \n", programm[i].id);
		printf("if_did_anyone          == %d and %d\n",
			programm[i].if_did_anyone[0], programm[i].if_did_anyone[1]);
		printf("philo->time_to_die     == %lld \n", programm[i].time_to_die);
		printf("philo->time_to_eat     == %lld \n", programm[i].time_to_eat);
		printf("philo->time_to_sleep   == %lld \n", programm[i].time_to_sleep);
		printf("number_of_times_each_philosopher_must_eat   == %d \n",
			programm[i].number_of_eat);
		printf("------------------------\n\n\n");
		i++;
	}
}

void	func_philo_print_philosophers(t_data *programm)
{
	int	i;

	i = 0;
	while (i < programm[0].number_of_philosophers)
	{
		printf("programm->philo[i].id           == %d \n",
			programm[i].philo->id);
		printf("programm->philo[i].number_eat   == %d \n",
			programm[i].philo->number_eat);
		printf("programm->philo[i].time_die     == %lld \n",
			programm[i].philo->time_die);
		printf("programm->philo[i].time_eat     == %lld \n",
			programm[i].philo->time_eat);
		printf("programm->philo[i].time_sleep   == %lld \n",
			programm[i].philo->time_sleep);
		printf("------------------------\n\n\n");
		i++;
	}
}

void	initial_philo(t_data *philo_struct)
{
	int	i;

	if (!philo_struct)
		return ;
	i = 0;
	while (i < philo_struct[0].number_of_philosophers)
	{
		philo_struct[i].philo->id = i;
		philo_struct[i].id = i;
		philo_struct[i].philo->time_die = 0;
		philo_struct[i].philo->time_eat = 0;
		philo_struct[i].philo->time_sleep = 0;
		philo_struct[i].philo->number_eat = 0;
		philo_struct[i].philo->x = 0;
		philo_struct[i].philo->y = 0;
		i++;
	}
}

void	parsing(t_data *philo_struct,
	int count, char **argv, int number_of_philosophers)
{
	philo_struct->if_did_anyone[0] = 0;
	philo_struct->if_did_anyone[1] = 0;
	philo_struct->if_did_anyone[2] = 0;
	philo_struct->if_did_anyone[3] = 0;
	if (count == 6)
		philo_struct->number_of_eat = ft_atoi(argv[5]);
	else
		philo_struct->number_of_eat = 0;
	philo_struct->number_of_philosophers = number_of_philosophers;
	philo_struct->time_to_die = ft_atoi(argv[2]);
	philo_struct->time_to_eat = ft_atoi(argv[3]);
	philo_struct->time_to_sleep = ft_atoi(argv[4]);
}

t_data	*initial_value(int count, char **argv,
	int number_of_philosophers, int i)
{
	t_data			*philo_struct;
	t_philo_data	*philo;

	philo_struct = malloc(sizeof(t_data) * number_of_philosophers);
	philo = malloc(sizeof(t_philo_data) * number_of_philosophers);
	philo_struct[0]
		.forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	philo_struct[0].time = (long long int *)malloc(sizeof(long long int) * 4);
	philo_struct[0].if_did_anyone = (int *)malloc(sizeof(int) * 4);
	if (!philo_struct || !philo
		|| !philo_struct[0].if_did_anyone || !philo_struct[0].forks)
		return (NULL);
	while (++i < number_of_philosophers)
	{
		philo_struct[i].forks = philo_struct[0].forks;
		philo_struct[i].philo = &(philo[i]);
		philo_struct[i].if_did_anyone = philo_struct[0].if_did_anyone;
		philo_struct[i].time = philo_struct[0].time;
		parsing(&philo_struct[i], count, argv, number_of_philosophers);
	}
	initial_philo(philo_struct);
	return (philo_struct);
}
