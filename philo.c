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

static void	ph_clean(t_philo *philo)
{
	int	i;

	i = 0;
	free(philo->id);
	free(philo->philo);
	while (i < philo->in->n_philo)
		pthread_mutex_destroy(philo->fork + i);
	free(philo);
}

static t_philo	*ph_declaration(t_input *input)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (philo == NULL)
		return ((t_philo *) NULL);
	philo->id = (int *) malloc(sizeof(int) * input->n_philo);
	philo->philo = (pthread_t *) malloc(sizeof(pthread_t)
			* (input->n_philo + 1));
	philo->fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t)
			* input->n_philo);
	if (philo->id == NULL || philo->philo == NULL || philo->fork == NULL)
	{
		err_exit(ERR_MSG_MALLOC);
		if (philo->id != NULL)
			free(philo->id);
		if (philo->philo != NULL)
			free(philo->philo);
		if (philo->fork != NULL)
			free(philo->fork);
		free(philo);
		return ((t_philo *) NULL);
	}
	return (philo);
}

static t_philo	*ph_initialization(t_input	*input)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ph_declaration(input);
	if (philo == NULL)
		return ((t_philo *) NULL);
	philo->in = input;
	while (i < input->n_philo)
	{
		if (pthread_create(philo->philo + i, NULL, ph_life, &i) != 0)
		{
			err_exit(ERR_MSG_PTHCRE);
			ph_clean(philo);
			return ((t_philo *) NULL);
		}
		philo->id[i] = i++;
	}
	return (philo);
}

int	ph_philosophers(t_input *input)
{
	t_philo	*philo;

	philo = ph_initialization(input);
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_join(*(philo->philo + philo->in->n_philo -1), NULL);
	ph_clean(philo);
	return (EXIT_SUCCESS);
}
