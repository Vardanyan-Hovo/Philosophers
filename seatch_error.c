/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seatch_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:40:34 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/16 23:23:37 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	shearch_error(char **argv)
{
	if (!argv[1] || ft_atoi(argv[1]) < 1)
	{
		printf("Incorrect input\n");
		return (1);
	}
	if (!argv[2] || ft_atoi(argv[2]) < 1)
	{
		printf("Incorrect input\n");
		return (1);
	}
	if (!argv[3] || ft_atoi(argv[3]) < 1
		|| !argv[4] || ft_atoi(argv[4]) < 1)
	{
		printf("Incorrect input\n");
		return (1);
	}
	if (argv[5] && ft_atoi(argv[5]) < 1)
	{
		printf("Incorect input\n");
		return (0);
	}
	return (0);
}
