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

# include "parser.h"

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

# define GOOD 0
# define DIE  1
# define END  2

typedef long long int	t_time;

struct					s_philo;

typedef struct s_info
{
	int				philo_die;
	int				philo_end;
	int				n_ph;
	t_time			t_die;
	t_time			t_eat;
	t_time			t_sleep;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	long long int	id;
	long long int	n_eat;
	t_time			t_life;
	t_time			t_die;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_info			*info;
}	t_philo;

int				ph_philosophers(t_input *input);

void			ph_print_action(t_philo *ph, const char *log);

void			*ph_life(void *a);

int				ph_take_fork(t_philo *ph);
int				ph_eat(t_philo *ph);
int				ph_sleep(t_philo *ph);
int				ph_think(t_philo *ph);

void			err_exit(const char *format);
long long int	get_uint(const char *str);
int				ph_wait(t_time len_time, t_philo *ph);

#endif
