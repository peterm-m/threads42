/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:21 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	ft_atol(const char *str)
{
	unsigned long int	c;
	int					sing;

	c = 0;
	sing = 1;
	while (*str == ' ' || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
	{
		sing = 44 - *str;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		c = (c * 10) + (*str - '0');
		str++;
	}
	if (c > LONG_MAX && sing == 1)
		return (-1);
	if (c > (unsigned long int)(-LONG_MIN) && sing == -1)
		return (0);
	return (c * sing);
}

static int	isnum(const char *str)
{
	while (*str == ' ' || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	else
		return (1);
}

unsigned int	get_uint(const char *str)
{
	long	res;

	if (isnum(str) == 0)
		return (0);
	res = ft_atol(str);
	if (res > INT_MAX || res <= 0)
		return (0);
	return ((unsigned int) res);
}

void	err_exit(const char *format)
{
	printf("%s\n", format);
	return ;
}
