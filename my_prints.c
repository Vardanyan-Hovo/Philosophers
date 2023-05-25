/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:33:24 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/16 23:20:44 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	time_period(t_data *data)
{
	long long int	x;

	x = my_time();
	if (data->if_did_anyone[2] && data->if_did_anyone[2] >= x)
		return (0);
	if (data->if_did_anyone[0] != 1)
		return (x - data->time[0]);
	return (0);
}

void	my_prints(int evnt, int id, t_data *data)
{
	data->time[3] = time_period(data);
	if (data->if_did_anyone[0] && evnt == 8)
	{
		printf("%d %d is dided\n",
			data->if_did_anyone[2], data->if_did_anyone[1] + 1);
		return ;
	}
	if (evnt == 1 && !data->if_did_anyone[0])
		printf("%lld %d has taken a fork left\n", data->time[3], id + 1);
	if (evnt == 2 && !data->if_did_anyone[0])
		printf("%lld %d has taken a fork right\n", data->time[3], id + 1);
	if (evnt == 3 && !data->if_did_anyone[0])
		printf("%lld %d is eating\n", data->time[3], id + 1);
	if (evnt == 4 && !data->if_did_anyone[0])
		printf("%lld %d is sleeping\n", data->time[3], id + 1);
	if (evnt == 6 && !data->if_did_anyone[0])
		printf("%lld %d is thinking\n", data->time[3], id + 1);
	if (evnt == 5 && data->if_did_anyone[1] == -1)
		printf("%d EVERYONE ATE %d\n",
			data->if_did_anyone[2], data->number_of_eat);
}

void	mutex_detech(t_data *func_live_programm)
{
	int	i;

	i = 0;
	while (i < func_live_programm->number_of_philosophers)
	{
		pthread_mutex_destroy(&(func_live_programm->forks[i]));
		i++;
	}
}
