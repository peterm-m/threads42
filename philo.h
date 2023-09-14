/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:15 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/types.h>
# include <sys/time.h>

# include <limits.h>

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

# define ERR_MSG_NARGS "Incorrect number of arguments"
# define ERR_MSG_VARGS "No valid argument"
# define ERR_MSG_MALLOC "Malloc error"
# define ERR_MSG_PTHCRE "Thread creation error"
# define ERR_MSG_MTXCRE "Mutex creation error"

# define LOG_FORK " has taken a fork"
# define LOG_EAT " is eating"
# define LOG_SLEEP " is sleeping"
# define LOG_THINK " is thinking"
# define LOG_DIE " died"


/*
*	unsigned int	n_phil
*	unsigned int	t_die
*	unsigned int	t_eat
*	unsigned int	t_sleep
*	int				n_eat
*/

typedef struct s_input
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				n_eat;
}	t_input;

typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
}	t_philo;

//typedef struct s_philo
//{
//	t_input			*in;
//	int				*id;
//	pthread_t		*philo;
//	pthread_mutex_t	*fork;
//}	t_philo;

int				ph_philosophers(t_input *input);

void			ph_print_action(int time, int id, const char *log);

void			*ph_life(void *a);
void			ph_eat(int i);
void			ph_sleep(int i);
void			ph_think(int i);

void			err_exit(const char *format);
unsigned int	get_uint(const char *str);

#endif
