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

static int	ph_day(t_philo *a)
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
	int						out;
	t_philo					*ph;

	ph = (t_philo *) a;
	ph->t_life = (t_time) 0;
	ph->t_die = ((t_philo *)a)->info->t_die;
	while ((ph->info->philo_die != 1) && (ph->info->philo_end != ph->info->n_ph))
	{
		out = ph_day(ph);
		if (out == DIE || out == END)
		{
			pthread_mutex_lock(&creation);
			if (out == DIE)
				ph->info->philo_die = 1;
			else
				ph->info->philo_end += 1;
			pthread_mutex_unlock(&creation);
		}
	}
	return (a);
}
