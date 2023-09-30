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

int	ph_take_fork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->philo[ph->id -1].fork));
	ph_print_action(ph, LOG_FORK);
	pthread_mutex_lock(&(ph->info->philo[ph->id % ph->info->n_ph].fork));
	ph_print_action(ph, LOG_FORK);
	return (GOOD);
}

int	ph_drop_fork(t_philo *ph)
{
	pthread_mutex_unlock(&(ph->info->philo[ph->id -1].fork));
	pthread_mutex_unlock(&(ph->info->philo[ph->id % ph->info->n_ph].fork));
	return (GOOD);
}

int	ph_eat(t_philo *ph)
{
	int	out;

	out = ph_take_fork(ph);
	if (out == DIE)
		return (DIE);
	out = ph_wait(ph->info->t_eat, ph);
	if (out == GOOD && ph->info->philo_die == 0)
		ph_print_action(ph, LOG_EAT);
	else if (out == DIE)
	{
		ph->info->philo_die = 1;	
		ph_drop_fork(ph);
		ph_print_action(ph, LOG_DIE);
		return (out);
	}
	ph_drop_fork(ph);
	ph->n_eat -= 1;
	ph->t_die = ph->info->t_die;
	if (ph->n_eat != 0)
		return (out);
	else
		return (END);
}

int	ph_sleep(t_philo *ph)
{
	int	out;

	out = ph_wait(ph->info->t_sleep, ph);
	if (out == GOOD && ph->info->philo_die == 0)
		ph_print_action(ph, LOG_SLEEP);
	else
	{
		ph->info->philo_die = 1;
		ph_print_action(ph, LOG_DIE);
	}
	return (out);
}

int	ph_think(t_philo *ph)
{
	ph_print_action(ph, LOG_THINK);
	return (GOOD);
}
