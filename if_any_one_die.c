/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_any_one_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:30:30 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/24 15:48:14 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_all_are_eaten(t_data	*philo_programm)
{
	int	j;

	j = 0;
	if (!philo_programm[0].number_of_eat)
		return (0);
	while (j < philo_programm[0].number_of_philosophers)
	{
		if (philo_programm[j].philo->number_eat
			<= philo_programm[j].number_of_eat)
			return (0);
		j++;
	}
	philo_programm[0].if_did_anyone[0] = 1;
	philo_programm[0].if_did_anyone[1] = -1;
	philo_programm[0].if_did_anyone[2] = my_time() - philo_programm[0].time[0];
	return (1);
}

int	if_did_philosophers(t_data *data)
{
	if (data->philo->x >= data->time_to_die)
	{
		data->if_did_anyone[0] = 1;
		data->if_did_anyone[1] = data->philo->id;
		data->if_did_anyone[2] = my_time() - data->time[0];
		my_prints(8, 28, data);
		return (1);
	}
	return (0);
}

void	free_all(t_data *philo_programm)
{
	int	i;
	int	n;

	i = 0;
	n = philo_programm[0].number_of_philosophers;
	while (i < n)
	{
		if (philo_programm[i].thread)
			pthread_detach(philo_programm[i].thread);
		i++;
	}
	if (philo_programm[0].philo)
		free(philo_programm[0].philo);
	if (philo_programm[0].time)
		free(philo_programm[0].time);
	if (philo_programm[0].forks)
		free(philo_programm[0].forks);
	if (philo_programm[0].if_did_anyone)
		free(philo_programm[0].if_did_anyone);
	if (philo_programm)
		free(philo_programm);
}

int	if_any_one_die(t_data *philo_programm, int i)
{
	t_data	data;

	data = philo_programm[0];
	while (data.if_did_anyone[0] == 0)
	{
		if (++i >= data.number_of_philosophers)
			i = 0;
		data = philo_programm[i];
		data.time[1] = my_time();
		data.philo->x = data.time[1] - data.philo->time_eat;
		pthread_mutex_lock(&data.meals);
		if (if_all_are_eaten(philo_programm))
		{
			my_prints(5, data.id, &philo_programm[i]);
			free_all(philo_programm);
			return (0);
		}
		if (if_did_philosophers(&data))
		{
			free_all(philo_programm);
			return (1);
		}
		pthread_mutex_unlock(&data.meals);
	}
	return (1);
}
