/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:09:08 by pedro             #+#    #+#             */
/*   Updated: 2023/09/13 19:10:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_day(void *a)
{
	t_philo		*philo;
	int			out;

	philo = (t_philo *)a;
	out = ph_think(philo);
	if (out == DIE)
		return (out);
	out = ph_eat(philo);
	if (out == DIE || out == END)
		return (out);
	out = ph_sleep(philo);
	if (out == DIE)
		return (out);
	return (GOOD);
}

void	*ph_life(void *a)
{
	static pthread_mutex_t	creation = PTHREAD_MUTEX_INITIALIZER;
	static int				philo_created = 0;
	static int				philo_die = 0;
	static int				philo_end = 0;
	int						out;

	pthread_mutex_lock(&creation);
	philo_created += 1;
	pthread_mutex_unlock(&creation);
	while ((philo_die != 1) && (philo_end < philo_created))
	{
		out = ph_day(a);
		if (out == DIE || out == END)
		{
			pthread_mutex_lock(&creation);
			if (out == DIE)
				philo_die = 1;
			else
				philo_end += 1;
			pthread_mutex_unlock(&creation);
		}
	}
	return (a);
}
