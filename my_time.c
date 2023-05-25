/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:46 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/16 17:17:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	my_time(void)
{
	int				x;
	struct timeval	t;

	x = gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
