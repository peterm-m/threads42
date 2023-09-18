/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:09 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:11 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_clean(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_ph)
	{
		pthread_mutex_destroy(&(info->philo[i].fork));
		i++;
	}
	free(info->philo);
	free(info);
}

static t_info	*ph_info(t_input *input)
{
	t_info	*info;

	info = (t_info *) malloc(sizeof(t_info));
	if (info == NULL)
		return ((t_info *) NULL);
	info->n_ph = input->n_ph;
	info->t_die = input->t_die;
	info->t_eat = input->t_eat;
	info->t_sleep = input->t_sleep;
	info->philo = (t_philo *) malloc(sizeof(t_philo) * info->n_ph);
	if (info->philo == NULL)
	{
		free(info);
		return ((t_info *) NULL);
	}
	return (info);
}

static void	ph_philo_ini(t_info *info, t_input *input)
{
	int	i;

	i = -1;
	while (++i < info->n_ph)
	{
		info->philo[i].id = i +1;
		info->philo[i].n_eat = input->n_eat;
		info->philo[i].info = info;
	}
	return ;
}

static t_info	*ph_philo_launcher(t_info *info)
{
	int		i;
	int		out;

	i = -1;
	out = 0;
	while (++i < info->n_ph && out == 0)
	{
		out = pthread_mutex_init(&(info->philo[i].fork), NULL);
		if (out != 0)
			err_exit(ERR_MSG_MTXCRE);
		out = pthread_create(&(info->philo[i].thread), NULL, ph_life,
				&(info->philo[i]));
		if (out != 0)
			err_exit(ERR_MSG_PTHCRE);
		if (out != 0)
		{
			ph_clean(info);
			return ((t_info *) NULL);
		}
	}
	return (info);
}

int	ph_philosophers(t_input *input)
{
	t_info	*info;

	info = ph_info(input);
	if (info == NULL)
		return (EXIT_FAILURE);
	ph_philo_ini(info, input);
	info = ph_philo_launcher(info);
	if (info == NULL)
		return (EXIT_FAILURE);
	pthread_join(info->philo[info->n_ph -1].thread, NULL);
	ph_clean(info);
	return (EXIT_SUCCESS);
}
