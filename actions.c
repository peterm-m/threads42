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
	int	i;

	i = *(int *) a;
	while (1)
	{
		ph_think(i);
		ph_eat(i);
		ph_sleep(i);
	}
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
