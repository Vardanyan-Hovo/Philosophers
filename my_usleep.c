/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:36:41 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/14 20:38:07 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(long long x)
{
	long long int	start;
	long long int	end;

	if (x <= 0)
		return ;
	start = my_time();
	end = start;
	while (start < end + x)
	{
		start = my_time();
	}
	end = start;
}
