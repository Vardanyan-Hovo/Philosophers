/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:31:50 by hvardany          #+#    #+#             */
/*   Updated: 2022/09/14 20:32:23 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	myatoi(char *s)
{
	long int	x;

	x = 0;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		x *= 10;
		x += *s - '0';
		s++;
	}
	return (x);
}

int	ft_atoi(const char *str)
{
	char			*s;
	long int		x;
	long int		minus;

	minus = 1;
	x = 0;
	s = (char *) str;
	while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
	{
		s++;
	}
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		minus = -1;
		s++;
	}
	x = myatoi(s);
	x *= minus;
	return (x);
}
