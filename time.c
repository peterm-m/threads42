/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:21 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time	ph_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ph_wait(t_time len_time, t_philo *ph)
{
	t_time	t_origin;
	t_time	t_step;

	t_origin = ph_get_time();
	t_step = len_time;
	while ((ph_get_time() - t_origin < len_time) && (ph->t_die > 0))
	{
		ph->t_die -= t_step;
		ph->t_life += t_step;
		usleep(t_step);
	}
	return ((ph->t_die > 0) * GOOD + (ph->t_die <= 0) * DIE);
}
