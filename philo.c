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

static void	ph_clean(t_philo *philo, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->n_philo)
	{
		pthread_mutex_destroy(&(philo[i].fork));
		i++;
	}
	free(philo);
}

static t_philo	*ph_declaration(t_input *input)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo) * input->n_philo);
	if (philo == NULL)
		return ((t_philo *) NULL);
	return (philo);
}

static t_philo	*ph_initialization(t_philo *philo, t_input	*input)
{
	int		i;
	int		out;

	i = -1;
	out = 0;
	while (++i < input->n_philo && out == 0)
	{
		philo[i].id = i +1;
		out = pthread_mutex_init(&(philo[i].fork), NULL);
		if (out != 0)
			err_exit(ERR_MSG_MTXCRE);
		out = pthread_create(&(philo[i].thread), NULL, ph_life, &(philo[i]));
		if (out != 0)
			err_exit(ERR_MSG_PTHCRE);
		if (out != 0)
		{
			ph_clean(philo, input);
			return ((t_philo *) NULL);
		}
	}
	return (philo);
}

int	ph_philosophers(t_input *input)
{
	t_philo	*philo;

	philo = ph_declaration(input);
	if (philo == NULL)
		return (EXIT_FAILURE);
	ph_initialization(philo, input);
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_join(philo[input->n_philo -1].thread, NULL);
	ph_clean(philo, input);
	return (EXIT_SUCCESS);
}
