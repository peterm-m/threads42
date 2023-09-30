/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:10:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	t_input	*ph_parser(int argc, const char **argv)
{
	t_input	*i;

	i = (t_input *) malloc(sizeof(t_input));
	if (i == NULL)
	{
		err_exit(ERR_MSG_MALLOC);
		return (i);
	}	
	i->n_ph = (int)get_uint(argv[1]);
	i->t_die = (t_time)get_uint(argv[2]);
	i->t_eat = (t_time)get_uint(argv[3]);
	i->t_sleep = (t_time)get_uint(argv[4]);
	i->n_eat = -1;
	if (argc == 6)
		i->n_eat = (int) get_uint(argv[5]);
	if (i->n_ph == 0 || i->t_die == 0
		|| i->t_eat == 0 || i->t_sleep == 0 || i->n_eat == 0)
	{
		err_exit(ERR_MSG_VARGS);
		free(i);
		return ((t_input *) NULL);
	}
	return (i);
}

static void	ph_clean(t_input *input)
{
	free(input);
	return ;
}

int	main(int argc, char const **argv)
{
	t_input	*input;

	if (argc < 5 || argc > 6)
	{
		err_exit(ERR_MSG_NARGS);
		return (EXIT_FAILURE);
	}
	input = ph_parser(argc, argv);
	if (input == NULL)
		return (EXIT_FAILURE);
	if (ph_philosophers(input) == EXIT_FAILURE)
	{
		ph_clean(input);
		return (EXIT_FAILURE);
	}
	ph_clean(input);
	return (EXIT_SUCCESS);
}
