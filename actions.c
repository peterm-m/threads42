/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:09:08 by pedro             #+#    #+#             */
/*   Updated: 2023/09/13 19:10:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// critical section screen logs overlaps
void	ph_print_action(int time, t_philo *ph, const char *log)
{
	static pthread_mutex_t	screen = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&screen);
	printf("%d %d %s\n", time, ph->id, log);
	pthread_mutex_unlock(&screen);
	return ;
}

// critical section forks
void	ph_take_fork(t_philo *ph)
{
	ph_print_action(ph->id, ph, LOG_FORK);
	return ;
}

int	ph_eat(t_philo *ph)
{
	ph_print_action(ph->id, ph, LOG_EAT);
	return (GOOD);
}

int	ph_sleep(t_philo *ph)
{
	ph_print_action(ph->id, ph, LOG_SLEEP);
	return (GOOD);
}

int	ph_think(t_philo *ph)
{
	ph_print_action(ph->id, ph, LOG_THINK);
	return (GOOD);
}
