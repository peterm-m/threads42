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

void	*ph_life(void *a)
{
	static pthread_mutex_t	creation = PTHREAD_MUTEX_INITIALIZER;
	static int	philo_created = 0;
	static int	philo_lives = 0;
	t_philo	philo;

	pthread_mutex_lock(&creation);
	philo_created += 1;
	philo_lives += 1;
	pthread_mutex_unlock(&creation);
	philo = *(t_philo *)a;
	ph_think(philo.id);
	ph_eat(philo.id);
	ph_sleep(philo.id);
	return (a);
}

// critical section forks
void	ph_eat(int i)
{
	ph_print_action(i, i, LOG_EAT);
	return ;
}

void	ph_sleep(int i)
{
	ph_print_action(i, i, LOG_SLEEP);
	return ;
}

void	ph_think(int i)
{
	ph_print_action(i, i, LOG_THINK);
	return ;
}

// critical section screen logs overlaps
void	ph_print_action(int time, int id, const char *log)
{
	static pthread_mutex_t	screen = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&screen);
	printf("%d %d %s\n", time, id, log);
	pthread_mutex_unlock(&screen);
	return ;
}
